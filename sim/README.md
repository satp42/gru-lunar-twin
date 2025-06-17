# Transport Rover Simulation

## URDF Stub

The `models/transport_rover/transport_rover.urdf` contains a minimal Transport rover model with:

- Base chassis (blue box)
- Two front wheels (gray cylinders)
- Basic physics properties

## Viewing the Model

### Headless Testing
```bash
# Validate URDF loads correctly
./scripts/validate_urdf.sh
```

### With GUI (RViz)
```bash
# Launch with RViz visualization
ros2 launch sim/launch/view_stub.launch.py

# Note: Uncomment rviz_node in launch file for GUI systems
```

## Headless Simulation

### Running Headless Launch
```bash
# Launch headless simulation (no GUI)
ros2 launch sim/launch/headless.launch.py

# Test headless functionality
./scripts/test_headless.sh
```

### Expected Output
- Robot description published on `/robot_description` topic
- Transform frames published on `/tf` and `/tf_static`
- Model segments: base_link, front_left_wheel, front_right_wheel 