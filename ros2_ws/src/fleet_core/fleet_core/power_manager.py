#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from fleet_msgs.msg import BatteryStatus
import math


class PowerManager(Node):
    def __init__(self):
        super().__init__('power_manager')
        self.publisher_ = self.create_publisher(BatteryStatus, '/soc', 10)
        timer_period = 2.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.time_counter = 0
        self.get_logger().info('Power manager started, publishing to /soc')

    def timer_callback(self):
        msg = BatteryStatus()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.unit_id = 'excavator_001'
        # Simulate battery discharge cycle
        self.time_counter += 1
        msg.soc_percentage = 85.0 + 10.0 * math.sin(self.time_counter * 0.1)
        msg.voltage_v = 48.0 + 2.0 * math.sin(self.time_counter * 0.05)
        msg.charging = msg.soc_percentage < 90.0
        
        self.publisher_.publish(msg)
        self.get_logger().debug(f'Published SOC: {msg.soc_percentage:.1f}%')


def main(args=None):
    rclpy.init(args=args)
    power_manager = PowerManager()
    rclpy.spin(power_manager)
    power_manager.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main() 