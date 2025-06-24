#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from fleet_msgs.msg import BatteryStatus
from geometry_msgs.msg import Twist
import math


class PowerManager(Node):
    def __init__(self):
        super().__init__('power_manager')
        self.publisher_ = self.create_publisher(BatteryStatus, '/soc', 10)
        self.cmd_vel_sub = self.create_subscription(
            Twist, '/cmd_vel', self.cmd_vel_callback, 10)
        
        timer_period = 2.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        # Battery state
        self.soc_percentage = 100.0  # Start at full charge
        self.voltage_v = 48.0
        self.is_active = False
        self.last_activity_time = self.get_clock().now()
        
        self.get_logger().info('Power manager started, monitoring /cmd_vel and publishing to /soc')

    def cmd_vel_callback(self, msg):
        """Monitor fleet activity to consume battery"""
        # Check if there's any movement command
        if abs(msg.linear.x) > 0.01 or abs(msg.angular.z) > 0.01:
            self.is_active = True
            self.last_activity_time = self.get_clock().now()
        else:
            # Consider inactive if no significant movement for 5 seconds
            time_since_activity = (self.get_clock().now() - self.last_activity_time).nanoseconds / 1e9
            self.is_active = time_since_activity < 5.0

    def timer_callback(self):
        # Consume battery based on activity
        if self.is_active:
            # Active digging/moving: consume 0.5% per update (every 2s)
            self.soc_percentage = max(0.0, self.soc_percentage - 0.5)
            power_draw = 2.5  # kW when active
        else:
            # Idle: consume 0.1% per update
            self.soc_percentage = max(0.0, self.soc_percentage - 0.1)
            power_draw = 0.2  # kW when idle
        
        # Voltage drops as SOC decreases
        self.voltage_v = 42.0 + (self.soc_percentage / 100.0) * 6.0  # 42-48V range
        
        # Publish battery status
        msg = BatteryStatus()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.unit_id = 'excavator_001'
        msg.soc_percentage = self.soc_percentage
        msg.voltage_v = self.voltage_v
        msg.charging = False  # Not charging during operation
        
        self.publisher_.publish(msg)
        
        status = "ACTIVE" if self.is_active else "IDLE"
        self.get_logger().info(f'[{status}] SOC: {self.soc_percentage:.1f}%, '
                               f'Voltage: {self.voltage_v:.1f}V, Power: {power_draw:.1f}kW')


def main(args=None):
    rclpy.init(args=args)
    power_manager = PowerManager()
    rclpy.spin(power_manager)
    power_manager.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main() 