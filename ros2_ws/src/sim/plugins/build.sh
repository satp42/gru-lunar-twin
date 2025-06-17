#!/bin/bash

# Build script for the gravity plugin
# Handles clean builds to avoid CMake cache issues

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "Building gravity plugin..."

# Clean existing build directory to avoid cache issues
if [ -d "build" ]; then
    echo "Cleaning existing build directory..."
    rm -rf build
fi

# Create fresh build directory
mkdir -p build
cd build

# Configure with cmake
echo "Configuring with CMake..."
cmake ..

# Build the plugin
echo "Building plugin..."
make

echo "Build complete! Plugin library created:"
ls -la libgravity_plugin.so 2>/dev/null || echo "Plugin not found - check build output above"

# Add to plugin path
echo ""
echo "To use the plugin, add this to your environment:"
echo "export GAZEBO_PLUGIN_PATH=\$GAZEBO_PLUGIN_PATH:$(pwd)" 