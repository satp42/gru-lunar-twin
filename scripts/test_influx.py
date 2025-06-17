#!/usr/bin/env python3

import sys
from datetime import datetime

try:
    from influxdb_client import InfluxDBClient, Point, WritePrecision
    from influxdb_client.client.write_api import SYNCHRONOUS
except ImportError:
    print("Install InfluxDB client: pip install influxdb-client")
    sys.exit(1)

def test_influx():
    """Test InfluxDB connection and write sample data"""
    print("Testing InfluxDB connectivity...")
    
    client = InfluxDBClient(
        url="http://localhost:8086",
        token="H2GlSQE2_vzpNguuw5tl5bQ_074jUVoeO-j_PlJiJkadgcxUArk1e4c7REE4ZJej8Se0DWReqhL8L9YeK1U8nQ==",
        org="primary"
    )
    
    try:
        # Test connection
        health = client.health()
        print(f"✅ InfluxDB health: {health.status}")
        
        # Write test data
        write_api = client.write_api(write_options=SYNCHRONOUS)
        
        point = Point("battery_status") \
            .tag("unit_id", "excavator_001") \
            .field("soc_percentage", 88.5) \
            .field("voltage_v", 49.2) \
            .field("charging", True) \
            .time(datetime.utcnow(), WritePrecision.NS)
        
        write_api.write(bucket="fleet_data", org="primary", record=point)
        print("✅ Test data written to InfluxDB")
        
        # Query test
        query_api = client.query_api()
        query = '''
            from(bucket: "fleet_data")
            |> range(start: -1h)
            |> filter(fn: (r) => r._measurement == "battery_status")
            |> filter(fn: (r) => r._field == "soc_percentage")
        '''
        
        tables = query_api.query(query=query)
        count = 0
        for table in tables:
            count += len(table.records)
        
        print(f"✅ Query returned {count} records")
        client.close()
        return True
        
    except Exception as e:
        print(f"❌ InfluxDB error: {e}")
        return False

if __name__ == "__main__":
    success = test_influx()
    sys.exit(0 if success else 1) 