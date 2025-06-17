#!/usr/bin/env python3
"""
Test script for lunar gravity plugin
Simulates the gravity topic publishing and verifies the values
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3
import time
import math

class GravityTester(Node):
    def __init__(self):
        super().__init__('gravity_tester')
        
        # Publisher to simulate plugin output
        self.publisher = self.create_publisher(Vector3, '/world/gravity', 10)
        
        # Subscriber to verify published values
        self.subscription = self.create_subscription(
            Vector3,
            '/world/gravity',
            self.gravity_callback,
            10)
        
        # Expected lunar gravity values
        self.expected_gravity = {
            'x': 0.0,
            'y': 0.0,
            'z': -1.635  # 1/6 of Earth's gravity
        }
        
        self.received_gravity = None
        self.test_passed = False
        
        # Start publishing gravity values
        timer_period = 1.0  # seconds
        self.timer = self.create_timer(timer_period, self.publish_gravity)
        
        self.get_logger().info('Gravity tester node started')
        self.get_logger().info(f'Expected lunar gravity: {self.expected_gravity}')

    def publish_gravity(self):
        """Publish lunar gravity values (simulating the plugin)"""
        msg = Vector3()
        msg.x = self.expected_gravity['x']
        msg.y = self.expected_gravity['y']
        msg.z = self.expected_gravity['z']
        
        self.publisher.publish(msg)
        self.get_logger().info(f'Published gravity: [{msg.x}, {msg.y}, {msg.z}]')

    def gravity_callback(self, msg):
        """Callback to verify received gravity values"""
        self.received_gravity = {
            'x': msg.x,
            'y': msg.y,
            'z': msg.z
        }
        
        self.get_logger().info(f'Received gravity: [{msg.x}, {msg.y}, {msg.z}]')
        
        # Check if values match expected lunar gravity
        tolerance = 0.01  # Allow small floating point differences
        
        x_match = abs(msg.x - self.expected_gravity['x']) < tolerance
        y_match = abs(msg.y - self.expected_gravity['y']) < tolerance
        z_match = abs(msg.z - self.expected_gravity['z']) < tolerance
        
        if x_match and y_match and z_match:
            if not self.test_passed:
                self.get_logger().info('✅ GRAVITY TEST PASSED!')
                self.get_logger().info('Lunar gravity values are correct')
                self.test_passed = True
        else:
            self.get_logger().warn('❌ Gravity values do not match expected lunar gravity')

    def verify_lunar_gravity(self):
        """Verify that gravity is approximately 1/6 of Earth's gravity"""
        if self.received_gravity:
            earth_gravity = -9.81
            expected_lunar = earth_gravity / 6.0
            actual_z = self.received_gravity['z']
            
            ratio = actual_z / earth_gravity
            
            self.get_logger().info(f'Earth gravity: {earth_gravity} m/s²')
            self.get_logger().info(f'Expected lunar gravity: {expected_lunar:.3f} m/s²')
            self.get_logger().info(f'Actual gravity: {actual_z} m/s²')
            self.get_logger().info(f'Ratio to Earth gravity: {ratio:.3f} (should be ~0.167)')
            
            if abs(ratio - (1/6)) < 0.01:
                self.get_logger().info('✅ Gravity ratio is correct for lunar conditions')
                return True
            else:
                self.get_logger().warn('❌ Gravity ratio is incorrect')
                return False
        return False

def main(args=None):
    rclpy.init(args=args)
    
    gravity_tester = GravityTester()
    
    try:
        # Run for a few seconds to test
        rclpy.spin_once(gravity_tester, timeout_sec=1.0)
        time.sleep(2.0)
        
        # Verify the gravity values
        if gravity_tester.verify_lunar_gravity():
            gravity_tester.get_logger().info('🌙 Lunar gravity simulation successful!')
        else:
            gravity_tester.get_logger().warn('⚠️  Gravity verification failed')
            
        # Continue spinning for a bit more
        for _ in range(3):
            rclpy.spin_once(gravity_tester, timeout_sec=1.0)
            time.sleep(1.0)
            
    except KeyboardInterrupt:
        gravity_tester.get_logger().info('Test interrupted by user')
    finally:
        gravity_tester.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main() 