#!/bin/bash

# Service management script for InfluxDB v2 and Grafana
# Usage: ./scripts/brew_services.sh [start|stop|status]

set -e

ACTION=${1:-status}

start_services() {
    echo "🚀 Starting InfluxDB and Grafana services..."
    brew services start influxdb
    brew services start grafana
    echo "✅ Services started"
    echo "📊 InfluxDB: http://localhost:8086"
    echo "📈 Grafana: http://localhost:3000"
}

stop_services() {
    echo "🛑 Stopping InfluxDB and Grafana services..."
    brew services stop influxdb
    brew services stop grafana
    echo "✅ Services stopped"
}

status_services() {
    echo "📊 Service Status:"
    brew services list | grep -E "(influxdb|grafana)"
}

case $ACTION in
    start)
        start_services
        ;;
    stop)
        stop_services
        ;;
    status)
        status_services
        ;;
    *)
        echo "Usage: $0 [start|stop|status]"
        exit 1
        ;;
esac 