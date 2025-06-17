#!/bin/bash

# rosbag2 recording script for fleet operations
# Records key topics to data/bagfiles directory

set -e

# Create bagfiles directory if it doesn't exist
mkdir -p data/bagfiles

# Set bag name with timestamp
BAG_NAME="fleet_$(date +%Y%m%d_%H%M%S)"
BAG_PATH="data/bagfiles/${BAG_NAME}"

# Duration to record (default 10 seconds)
DURATION=${1:-10}

echo "Recording bag to: ${BAG_PATH}"
echo "Duration: ${DURATION} seconds"

# Record key fleet topics with simplified syntax
ros2 bag record \
    -o ${BAG_PATH} \
    -d ${DURATION} \
    /cmd_vel

echo "Recording complete. Bag saved to: ${BAG_PATH}"
ls -lh ${BAG_PATH}/ 2>/dev/null || echo "Checking bag contents..."
find ${BAG_PATH} -type f -exec ls -lh {} \; 2>/dev/null || echo "No files in bag directory" 