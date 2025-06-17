#!/bin/bash

# Headless Launch Test Script
# Tests that the headless launch file starts correctly

set -e

echo "🚀 Testing headless launch..."

# Start the headless launch in background
echo "📡 Starting headless simulation..."
ros2 launch sim/launch/headless.launch.py &
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
echo "🔧 Cleaning up..."
kill $LAUNCH_PID 2>/dev/null || true
wait $LAUNCH_PID 2>/dev/null || true

echo "🎉 Headless launch test successful!"
exit 0 