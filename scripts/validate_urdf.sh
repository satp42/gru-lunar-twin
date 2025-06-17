#!/bin/bash

# URDF Validation Script for Transport Rover
# Tests that the URDF loads correctly and publishes robot description

set -e

echo "🚀 Testing Transport Rover URDF stub..."

# Run the launch file in background
echo "📡 Starting robot state publisher..."
timeout 10s ros2 launch sim/launch/view_stub.launch.py &
LAUNCH_PID=$!

# Wait for startup
sleep 3

# Check that robot description topic exists
echo "🔍 Checking robot description topic..."
if ros2 topic list | grep -q "/robot_description"; then
    echo "✅ Robot description topic found"
else
    echo "❌ Robot description topic not found"
    kill $LAUNCH_PID 2>/dev/null || true
    exit 1
fi

# Check robot description content
echo "🔍 Validating URDF content..."
ROBOT_DESC=$(ros2 topic echo /robot_description --once)
if echo "$ROBOT_DESC" | grep -q "transport_rover"; then
    echo "✅ Transport rover found in robot description"
else
    echo "❌ Transport rover not found in robot description"
    kill $LAUNCH_PID 2>/dev/null || true
    exit 1
fi

# Check TF topics are being published
echo "🔍 Checking TF topics..."
if ros2 topic list | grep -q "/tf"; then
    echo "✅ TF topic found"
else
    echo "❌ TF topic not found"
    kill $LAUNCH_PID 2>/dev/null || true
    exit 1
fi

# Clean up
kill $LAUNCH_PID 2>/dev/null || true
wait $LAUNCH_PID 2>/dev/null || true

echo "🎉 URDF validation successful! Model ready for RViz visualization." 