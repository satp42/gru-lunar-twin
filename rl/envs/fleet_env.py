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
        # Simple action mapping for testing
        if action == 1:  # north
            self.rover_pos[1] += 1.0
        elif action == 2:  # south  
            self.rover_pos[1] -= 1.0
        elif action == 3:  # east
            self.rover_pos[0] += 1.0
        elif action == 4:  # west
            self.rover_pos[0] -= 1.0
        
        # Consume battery
        self.rover_battery = max(0.0, self.rover_battery - 0.1)
        
        # Basic reward: penalty for battery drain
        reward = -0.1 if action != 0 else 0.0
        
        observation = np.array([
            self.rover_pos[0], self.rover_pos[1], self.rover_battery,
            self.excavator_pos[0], self.excavator_pos[1], self.excavator_battery,
            self.excavated_kg
        ], dtype=np.float32)
        
        terminated = self.rover_battery <= 0.0
        truncated = False
        info = {}
        
        return observation, reward, terminated, truncated, info

    def close(self):
        pass 