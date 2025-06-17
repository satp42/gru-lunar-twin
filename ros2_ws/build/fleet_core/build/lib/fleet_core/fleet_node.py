#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class FleetNode(Node):
    def __init__(self):
        super().__init__('fleet_node')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        timer_period = 1.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('Fleet node started, publishing to /cmd_vel')

    def timer_callback(self):
        msg = Twist()
        msg.linear.x = 0.1
        msg.angular.z = 0.0
        self.publisher_.publish(msg)
        self.get_logger().debug('Published cmd_vel: linear.x=0.1')


def main(args=None):
    rclpy.init(args=args)
    fleet_node = FleetNode()
    rclpy.spin(fleet_node)
    fleet_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main() 