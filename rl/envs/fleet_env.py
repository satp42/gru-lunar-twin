import gymnasium as gym
import numpy as np
from gymnasium import spaces


class FleetEnv(gym.Env):
    """Minimal fleet environment for lunar excavator simulation"""
    
    def __init__(self):
        super().__init__()
        
        # Observation: [rover1_x, rover1_y, rover1_battery, excavator_x, excavator_y, excavator_battery, excavator_kg]
        self.observation_space = spaces.Box(
            low=np.array([-50.0, -50.0, 0.0, -50.0, -50.0, 0.0, 0.0], dtype=np.float32),
            high=np.array([50.0, 50.0, 100.0, 50.0, 50.0, 100.0, 1000.0], dtype=np.float32),
            dtype=np.float32
        )
        
        # Actions: 0=idle, 1=north, 2=south, 3=east, 4=west  
        self.action_space = spaces.Discrete(5)
        
        self._reset_state()

    def _reset_state(self):
        """Reset internal state"""
        self.rover_pos = np.array([0.0, 0.0], dtype=np.float32)
        self.rover_battery = 100.0
        self.excavator_pos = np.array([10.0, 10.0], dtype=np.float32) 
        self.excavator_battery = 100.0
        self.excavated_kg = 0.0
        self.steps_idle = 0
        self.prev_excavated_kg = 0.0

    def reset(self, seed=None, options=None):
        super().reset(seed=seed)
        self._reset_state()
        
        observation = np.array([
            self.rover_pos[0], self.rover_pos[1], self.rover_battery,
            self.excavator_pos[0], self.excavator_pos[1], self.excavator_battery,
            self.excavated_kg
        ], dtype=np.float32)
        
        info = {}
        return observation, info

    def step(self, action):
        # Track previous kg for excavation progress
        self.prev_excavated_kg = self.excavated_kg
        
        # Simple action mapping for testing
        if action == 1:  # north
            self.rover_pos[1] += 1.0
        elif action == 2:  # south  
            self.rover_pos[1] -= 1.0
        elif action == 3:  # east
            self.rover_pos[0] += 1.0
        elif action == 4:  # west
            self.rover_pos[0] -= 1.0
        
        # Consume battery and simulate excavation
        if action != 0:  # Moving
            self.rover_battery = max(0.0, self.rover_battery - 0.1)
            self.steps_idle = 0
            # Simulate excavation progress when moving (coordinated fleet)
            if self.excavator_battery > 10.0:
                self.excavated_kg += 0.5  # kg per step when coordinated
                self.excavator_battery = max(0.0, self.excavator_battery - 0.2)
        else:  # Idle
            self.steps_idle += 1
            # Idle excavator loses opportunity
            
        # Task 27: Reward shaping for fleet coordination
        reward = 0.0
        
        # Positive rewards for excavation progress
        kg_gained = self.excavated_kg - self.prev_excavated_kg
        if kg_gained > 0:
            reward += kg_gained * 2.0  # +1.0 reward for 0.5 kg progress
            
        # Penalty for idle excavator (24/7 operation target)
        if action == 0:
            idle_penalty = -0.5 * (1 + self.steps_idle * 0.1)  # Increasing penalty
            reward += idle_penalty
            
        # Small movement cost to balance
        if action != 0:
            reward -= 0.05  # Reduced from -0.1
            
        # Battery efficiency bonus
        if self.rover_battery > 50.0 and action != 0:
            reward += 0.1  # Encourage early activity
            
        observation = np.array([
            self.rover_pos[0], self.rover_pos[1], self.rover_battery,
            self.excavator_pos[0], self.excavator_pos[1], self.excavator_battery,
            self.excavated_kg
        ], dtype=np.float32)
        
        terminated = self.rover_battery <= 0.0 or self.excavator_battery <= 0.0
        truncated = False
        info = {
            'kg_gained': kg_gained,
            'idle_steps': self.steps_idle,
            'excavator_active': kg_gained > 0
        }
        
        return observation, reward, terminated, truncated, info

    def close(self):
        pass 