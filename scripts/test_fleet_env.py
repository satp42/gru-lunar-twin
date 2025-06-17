#!/usr/bin/env python3

import sys
import numpy as np

def test_fleet_env():
    """Test FleetEnv meets Task 20 acceptance criteria"""
    try:
        # Import and register environment
        import rl.envs
        import gymnasium as gym
        
        # Test: gym.make works
        env = gym.make('FleetEnv-v0')
        print("✅ gym.make('FleetEnv-v0') works")
        
        # Test: env.reset() returns ndarray
        observation, info = env.reset()
        
        if isinstance(observation, np.ndarray):
            print("✅ env.reset() returns ndarray")
            print(f"   Observation shape: {observation.shape}")
            print(f"   Observation dtype: {observation.dtype}")
            print(f"   Observation values: {observation}")
        else:
            print(f"❌ env.reset() returned {type(observation)}, expected ndarray")
            return False
            
        # Additional validation
        print(f"✅ Action space: {env.action_space}")
        print(f"✅ Observation space: {env.observation_space}")
        
        # Test a step
        action = env.action_space.sample()
        obs, reward, terminated, truncated, info = env.step(action)
        print(f"✅ env.step({action}) works")
        
        env.close()
        print("✅ Task 20 COMPLETE: Gymnasium env wrapper functional")
        return True
        
    except Exception as e:
        print(f"❌ Error: {e}")
        return False

if __name__ == "__main__":
    success = test_fleet_env()
    sys.exit(0 if success else 1) 