#!/bin/bash

# ROS 2 Docker Workspace Script
# Usage: ./scripts/ros_docker.sh [command]

set -e

WORKSPACE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../ros2_ws" && pwd)"
DOCKER_IMAGE="ros2-dev"

# Build Docker image if it doesn't exist
if ! docker image inspect $DOCKER_IMAGE > /dev/null 2>&1; then
    echo "Building ROS 2 Docker image..."
    docker build -t $DOCKER_IMAGE .
fi

# Default command if none provided
COMMAND=${1:-"bash"}

echo "Running ROS 2 workspace in Docker..."
echo "Workspace: $WORKSPACE_DIR"
echo "Command: $COMMAND"

# Run the container
docker run -it --rm \
    -v "$WORKSPACE_DIR:/workspace" \
    -w /workspace \
    $DOCKER_IMAGE \
    bash -c "source /opt/ros/humble/setup.bash && source install/setup.bash 2>/dev/null || true && $COMMAND" 