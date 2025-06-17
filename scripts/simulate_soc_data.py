#!/usr/bin/env python3

import time
import math
from datetime import datetime
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS

def simulate_soc_data():
    """Simulate power manager by writing SOC data directly to InfluxDB"""
    print("Starting SOC data simulation...")
    
    client = InfluxDBClient(
        url="http://localhost:8086",
        token="H2GlSQE2_vzpNguuw5tl5bQ_074jUVoeO-j_PlJiJkadgcxUArk1e4c7REE4ZJej8Se0DWReqhL8L9YeK1U8nQ==",
        org="primary"
    )
    
    write_api = client.write_api(write_options=SYNCHRONOUS)
    
    try:
        for i in range(60):  # Run for 60 iterations (2 minutes at 2s intervals)
            # Simulate battery discharge cycle
            soc_percentage = 85.0 + 10.0 * math.sin(i * 0.1)
            voltage_v = 48.0 + 2.0 * math.sin(i * 0.05)
            charging = soc_percentage < 90.0
            
            point = Point("battery_status") \
                .tag("unit_id", "excavator_001") \
                .field("soc_percentage", float(soc_percentage)) \
                .field("voltage_v", float(voltage_v)) \
                .field("charging", bool(charging)) \
                .time(datetime.now(), WritePrecision.NS)
            
            write_api.write(bucket="fleet_data", org="primary", record=point)
            
            print(f"Written: SOC={soc_percentage:.1f}%, V={voltage_v:.1f}V, Charging={charging}")
            time.sleep(2)  # Publish every 2 seconds
            
    except KeyboardInterrupt:
        print("\nStopping simulation...")
    finally:
        client.close()
        print("Simulation complete")

if __name__ == "__main__":
    simulate_soc_data() 