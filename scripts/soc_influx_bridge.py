#!/usr/bin/env python3

import os
import sys
import time
from datetime import datetime

# Add ROS paths
sys.path.append('/opt/homebrew/lib/python3.11/site-packages')

try:
    import rclpy
    from rclpy.node import Node
    from fleet_msgs.msg import BatteryStatus
except ImportError as e:
    print(f"ROS import error: {e}")
    print("Make sure ROS 2 is sourced: source /opt/homebrew/setup.bash")
    sys.exit(1)

try:
    from influxdb_client import InfluxDBClient, Point, WritePrecision
    from influxdb_client.client.write_api import SYNCHRONOUS
except ImportError as e:
    print(f"InfluxDB client not found: {e}")
    print("Install with: pip install influxdb-client")
    sys.exit(1)


class SOCInfluxBridge(Node):
    def __init__(self):
        super().__init__('soc_influx_bridge')
        
        # InfluxDB connection (local)
        self.client = InfluxDBClient(
            url="http://localhost:8086",
            token="H2GlSQE2_vzpNguuw5tl5bQ_074jUVoeO-j_PlJiJkadgcxUArk1e4c7REE4ZJej8Se0DWReqhL8L9YeK1U8nQ==",
            org="primary"
        )
        self.write_api = self.client.write_api(write_options=SYNCHRONOUS)
        self.bucket = "fleet_data"
        
        # ROS subscriber
        self.subscription = self.create_subscription(
            BatteryStatus,
            '/soc',
            self.soc_callback,
            10)
        
        self.get_logger().info('SOC InfluxDB bridge started')

    def soc_callback(self, msg):
        try:
            # Create InfluxDB point
            point = Point("battery_status") \
                .tag("unit_id", msg.unit_id) \
                .field("soc_percentage", float(msg.soc_percentage)) \
                .field("voltage_v", float(msg.voltage_v)) \
                .field("charging", bool(msg.charging)) \
                .time(datetime.utcnow(), WritePrecision.NS)
            
            # Write to InfluxDB
            self.write_api.write(bucket=self.bucket, org="primary", record=point)
            
            self.get_logger().debug(f'Wrote to InfluxDB: {msg.unit_id} SOC={msg.soc_percentage:.1f}%')
            
        except Exception as e:
            self.get_logger().error(f'Failed to write to InfluxDB: {str(e)}')

    def __del__(self):
        if hasattr(self, 'client'):
            self.client.close()


def main(args=None):
    rclpy.init(args=args)
    bridge = SOCInfluxBridge()
    
    try:
        rclpy.spin(bridge)
    except KeyboardInterrupt:
        pass
    finally:
        bridge.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main() 