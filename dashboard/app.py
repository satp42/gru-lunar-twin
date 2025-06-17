import streamlit as st
import plotly.graph_objects as go
import plotly.express as px
import pandas as pd
from datetime import datetime, timedelta
import time

try:
    from influxdb_client import InfluxDBClient
except ImportError:
    st.error("InfluxDB client not installed. Run: pip install influxdb-client")
    st.stop()

# Page config
st.set_page_config(page_title="Fleet Dashboard", layout="wide")

# InfluxDB connection
@st.cache_resource
def get_influx_client():
    return InfluxDBClient(
        url="http://localhost:8086",
        token="H2GlSQE2_vzpNguuw5tl5bQ_074jUVoeO-j_PlJiJkadgcxUArk1e4c7REE4ZJej8Se0DWReqhL8L9YeK1U8nQ==",
        org="primary"
    )

def query_soc_data(hours=1):
    """Query SOC data from InfluxDB"""
    client = get_influx_client()
    query = f'''
        from(bucket: "fleet_data")
        |> range(start: -{hours}h)
        |> filter(fn: (r) => r._measurement == "battery_status")
        |> filter(fn: (r) => r._field == "soc_percentage")
        |> sort(columns: ["_time"])
    '''
    
    try:
        tables = client.query_api().query(query=query)
        data = []
        for table in tables:
            for record in table.records:
                data.append({
                    'time': record.get_time(),
                    'unit_id': record.values.get('unit_id', 'unknown'),
                    'soc_percentage': record.get_value()
                })
        return pd.DataFrame(data)
    except Exception as e:
        st.error(f"Failed to query InfluxDB: {e}")
        return pd.DataFrame()

def query_voltage_data(hours=1):
    """Query voltage data from InfluxDB"""
    client = get_influx_client()
    query = f'''
        from(bucket: "fleet_data")
        |> range(start: -{hours}h)
        |> filter(fn: (r) => r._measurement == "battery_status")
        |> filter(fn: (r) => r._field == "voltage_v")
        |> sort(columns: ["_time"])
    '''
    
    try:
        tables = client.query_api().query(query=query)
        data = []
        for table in tables:
            for record in table.records:
                data.append({
                    'time': record.get_time(),
                    'unit_id': record.values.get('unit_id', 'unknown'),
                    'voltage_v': record.get_value()
                })
        return pd.DataFrame(data)
    except Exception as e:
        st.error(f"Failed to query voltage data: {e}")
        return pd.DataFrame()

# Main dashboard
st.title("🚀 Fleet Dashboard")
st.markdown("Real-time monitoring from InfluxDB")

# Sidebar controls
st.sidebar.header("Controls")
hours = st.sidebar.slider("Time Range (hours)", 1, 24, 1)
auto_refresh = st.sidebar.checkbox("Auto-refresh (5s)", value=True)

# Auto-refresh logic
if auto_refresh:
    time.sleep(0.1)  # Small delay to prevent too frequent updates
    st.rerun()

# Data sections
col1, col2 = st.columns(2)

with col1:
    st.subheader("🔋 Battery SOC")
    soc_df = query_soc_data(hours)
    
    if not soc_df.empty:
        fig_soc = go.Figure()
        for unit_id in soc_df['unit_id'].unique():
            unit_data = soc_df[soc_df['unit_id'] == unit_id]
            fig_soc.add_trace(go.Scatter(
                x=unit_data['time'],
                y=unit_data['soc_percentage'],
                mode='lines',
                name=unit_id,
                line=dict(width=3)
            ))
        
        fig_soc.update_layout(
            xaxis_title="Time",
            yaxis_title="SOC (%)",
            height=400,
            showlegend=True
        )
        st.plotly_chart(fig_soc, use_container_width=True)
        
        # Latest SOC values
        latest_soc = soc_df.groupby('unit_id').last()
        for unit_id, row in latest_soc.iterrows():
            st.metric(
                label=f"{unit_id} SOC",
                value=f"{row['soc_percentage']:.1f}%"
            )
    else:
        st.info("No SOC data found. Make sure the bridge is running and publishing data.")

with col2:
    st.subheader("⚡ Battery Voltage")
    voltage_df = query_voltage_data(hours)
    
    if not voltage_df.empty:
        fig_voltage = go.Figure()
        for unit_id in voltage_df['unit_id'].unique():
            unit_data = voltage_df[voltage_df['unit_id'] == unit_id]
            fig_voltage.add_trace(go.Scatter(
                x=unit_data['time'],
                y=unit_data['voltage_v'],
                mode='lines',
                name=unit_id,
                line=dict(width=3)
            ))
        
        fig_voltage.update_layout(
            xaxis_title="Time",
            yaxis_title="Voltage (V)",
            height=400,
            showlegend=True
        )
        st.plotly_chart(fig_voltage, use_container_width=True)
        
        # Latest voltage values
        latest_voltage = voltage_df.groupby('unit_id').last()
        for unit_id, row in latest_voltage.iterrows():
            st.metric(
                label=f"{unit_id} Voltage",
                value=f"{row['voltage_v']:.1f}V"
            )
    else:
        st.info("No voltage data found.")

# Status section
st.subheader("📊 System Status")
col3, col4, col5 = st.columns(3)

with col3:
    try:
        client = get_influx_client()
        client.ping()
        st.success("✅ InfluxDB Connected")
    except:
        st.error("❌ InfluxDB Disconnected")

with col4:
    data_points = len(soc_df) if not soc_df.empty else 0
    st.metric("Data Points", data_points)

with col5:
    if not soc_df.empty:
        last_update = soc_df['time'].max()
        st.metric("Last Update", last_update.strftime("%H:%M:%S"))
    else:
        st.metric("Last Update", "N/A") 