#!/bin/bash

echo "=== Task 19: Running SOC bridge test ==="

# Start ROS 2 Docker environment
echo "1. Starting ROS 2 Docker environment..."
docker run -d --rm --name ros2_bridge_test \
  -v "$(pwd):/workspace" \
  -w /workspace \
  --net host \
  osrf/ros:humble-desktop \
  bash -c "
    source /opt/ros/humble/setup.bash &&
    cd ros2_ws &&
    colcon build --packages-select fleet_msgs fleet_core &&
    source install/setup.bash &&
    echo 'Starting power_manager...' &&
    ros2 run fleet_core power_manager &
    echo 'Power manager PID:' \$! &&
    sleep 30 &&
    echo 'Test complete'
  "

# Wait for container to start
sleep 5

# Check if /soc topic is being published
echo "2. Checking /soc topic..."
docker exec ros2_bridge_test bash -c "
  source /opt/ros/humble/setup.bash &&
  cd ros2_ws &&
  source install/setup.bash &&
  timeout 10 ros2 topic echo /soc --once
"

echo "3. Starting bridge in background..."
source .venv/bin/activate
python3 scripts/soc_influx_bridge.py &
BRIDGE_PID=$!

echo "Bridge PID: $BRIDGE_PID"
sleep 10

echo "4. Checking data in InfluxDB..."
python3 scripts/test_influx.py

echo "5. Cleanup..."
kill $BRIDGE_PID 2>/dev/null || true
docker stop ros2_bridge_test 2>/dev/null || true

echo "=== Bridge test complete ====" 