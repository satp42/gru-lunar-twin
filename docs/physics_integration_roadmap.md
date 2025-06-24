# Physics Integration Roadmap

## Current State: Separate Simulations

- **Power Manager**: ROS 2 topic monitoring + hardcoded consumption rates
- **RL Environment**: Standalone gymnasium simulation with approximated dynamics
- **Gazebo Simulation**: Physics engine running but not connected to RL training

## Phase 1: Gazebo Power Physics (Task 28+)

```xml
<!-- In URDF: Add motor specifications -->
<transmission name="wheel_transmission">
  <joint name="wheel_joint">
    <hardwareInterface>effort_controllers/JointEffortController</hardwareInterface>
  </joint>
  <actuator name="wheel_motor">
    <mechanicalReduction>50</mechanicalReduction>
    <motorConstant>0.1</motorConstant>  <!-- Nm/A -->
    <maxCurrent>10.0</maxCurrent>        <!-- Amperes -->
  </actuator>
</transmission>
```

```python
# Enhanced power_manager.py
def calculate_power_consumption(self, joint_efforts, joint_velocities):
    """Calculate realistic power from Gazebo joint states"""
    total_power = 0.0
    for effort, velocity in zip(joint_efforts, joint_velocities):
        mechanical_power = abs(effort * velocity)  # Watts
        electrical_power = mechanical_power / motor_efficiency  # Account for losses
        total_power += electrical_power
  
    # Convert to battery consumption rate
    battery_drain_rate = total_power / battery_capacity_wh * 100  # %/hour
    return battery_drain_rate
```

## Phase 2: ROS 2 ↔ RL Bridge (Task 29+)

```python
# ros_gym_bridge.py
class RosFleetEnv(gym.Env):
    def __init__(self):
        self.ros_node = rclpy.create_node('rl_bridge')
        self.cmd_pub = self.ros_node.create_publisher(Twist, '/cmd_vel', 10)
        self.soc_sub = self.ros_node.create_subscription(BatteryStatus, '/soc', self.soc_callback, 10)
        self.joint_sub = self.ros_node.create_subscription(JointState, '/joint_states', self.joint_callback, 10)
      
    def step(self, action):
        # Send real ROS 2 command
        cmd = self.action_to_twist(action)
        self.cmd_pub.publish(cmd)
      
        # Wait for Gazebo to simulate physics
        time.sleep(0.1)
      
        # Get real observations from ROS topics
        obs = self.get_real_observations()
        reward = self.calculate_reward_from_real_sensors()
        return obs, reward, done, info
```

## Phase 3: Sensor-Based Rewards (Task 30+)

```python
def calculate_realistic_reward(self):
    # Real excavation progress from load cell
    kg_excavated = self.load_cell_reading / 9.81  # Convert N to kg
  
    # Real battery efficiency from motor controllers  
    power_efficiency = self.useful_work / self.total_power_consumed
  
    # Real localization accuracy from GPS/IMU fusion
    position_error = np.linalg.norm(self.gps_pos - self.planned_pos)
  
    reward = (
        kg_excavated * 2.0 +                    # Production bonus
        power_efficiency * 1.0 -               # Efficiency bonus  
        position_error * 0.1 -                 # Drift penalty
        self.mission_time_penalty()            # 24/7 uptime pressure
    )
    return reward
```

## Phase 4: Multi-Robot Coordination (Task 31+)

```python
class MultiRobotFleetEnv(gym.Env):
    def __init__(self):
        # Connect to multiple robot namespaces
        self.robots = {
            'transport_1': RobotInterface('/transport_1'),
            'transport_2': RobotInterface('/transport_2'), 
            'excavator': RobotInterface('/excavator')
        }
      
    def step(self, actions):
        # Dispatch actions to multiple robots simultaneously
        for robot_id, action in actions.items():
            self.robots[robot_id].execute(action)
          
        # Coordinate fleet behavior
        fleet_reward = self.calculate_fleet_efficiency()
        return obs, fleet_reward, done, info
```

## Implementation Priority

1. **✅ Current (Tasks 25-27)**: Proved RL coordination works with simulated dynamics
2. **🎯 Next (Tasks 28-30)**: Add realistic URDF motor specs + power calculations
3. **🔧 Phase 2 (Tasks 31-33)**: Bridge RL → ROS 2 → Gazebo for real control
4. **🚀 Phase 3 (Tasks 34-35)**: Multi-robot fleet with sensor-based rewards

## Why Start With Approximations?

This is actually **standard practice** in robotics RL:

- **Sim2Real Transfer**: Train on fast approximated dynamics, then fine-tune on real hardware
- **Safety**: Debug RL policies in controlled environment before expensive hardware tests
- **Speed**: Standalone simulation trains 100x faster than full physics
- **Modularity**: Each component can be tested independently

**Bottom Line**: We built the **correct architecture** with realistic behaviors, but used approximated dynamics for rapid prototyping. The integration path to full physics is well-defined.
