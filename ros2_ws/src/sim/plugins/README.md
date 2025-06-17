# Lunar Gravity Plugin

A Gazebo System plugin that sets gravity to 1/6 of Earth's gravity (lunar gravity) for simulating Moon-like conditions. 

**Updated for New Gazebo (gz-sim) API**

## Features

- Sets gravity to -1.635 m/s² (1/6 of Earth's -9.81 m/s²)
- Publishes gravity status to `/world/gravity` topic
- Works with modern Gazebo (gz-sim8+)
- Compatible with ROS2 integration

## Prerequisites

### Option 1: Native Installation
- Gazebo Garden/Harmonic (gz-sim8+)
- gz-cmake3, gz-transport13, gz-msgs10

### Option 2: Docker with ROS2 (Recommended)
Since Gazebo installation can be complex on macOS, use the existing ROS2 Docker setup:

```bash
# Build and run ROS2 container with Gazebo
./scripts/ros_docker.sh
```

## Building

### Native Build (if Gazebo is installed)
```bash
cd sim/plugins
chmod +x build.sh
./build.sh
```

### Docker Build
```bash
# Inside the ROS2 container
cd /workspace/sim/plugins
mkdir -p build && cd build
cmake ..
make
```

## Testing

### Method 1: Using gz-sim (if available)
```bash
# Set plugin path
export GZ_SIM_SYSTEM_PLUGIN_PATH=$GZ_SIM_SYSTEM_PLUGIN_PATH:$(pwd)/build

# Run simulation
gz sim ../worlds/lunar_gravity_test.world

# Monitor gravity in another terminal
gz topic -e -t /world/gravity
```

### Method 2: ROS2 Integration Test
```bash
# Inside ROS2 container
source /opt/ros/humble/setup.bash

# Test topic publishing (simulated)
ros2 topic pub /world/gravity geometry_msgs/Vector3 '{x: 0.0, y: 0.0, z: -1.635}' --once

# Subscribe to gravity topic
ros2 topic echo /world/gravity
```

Expected gravity vector: `[0, 0, -1.635]` m/s²

## Plugin Architecture

The plugin uses the new Gazebo System architecture:
- `ISystemConfigure`: Sets initial gravity on world startup
- `ISystemPostUpdate`: Publishes gravity status periodically

## Troubleshooting

**Gazebo Installation Issues**: Use the Docker approach with ROS2 for reliable testing.

**Plugin Not Loading**: Ensure the plugin path is set correctly:
```bash
export GZ_SIM_SYSTEM_PLUGIN_PATH=$GZ_SIM_SYSTEM_PLUGIN_PATH:/path/to/plugin
```

**Compatibility**: This plugin is designed for Gazebo Garden/Harmonic. For older versions, use the classic Gazebo plugin format.

## Usage in World Files

Add this to your world SDF file:

```xml
<plugin name="lunar_gravity" filename="liblunar_gravity_plugin.so"/>
```

The plugin will automatically set lunar gravity when the world loads. 