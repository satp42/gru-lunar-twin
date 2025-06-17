#!/usr/bin/env python3

import sys
sys.path.append('.')

import rl.envs
import gymnasium as gym
from stable_baselines3.common.env_checker import check_env

def test_sb3_compatibility():
    """Test FleetEnv compatibility with Stable Baselines3"""
    print("Testing FleetEnv compatibility with Stable Baselines3...")
    
    env = gym.make('FleetEnv-v0')
    
    # Use SB3's env_checker to validate our environment
    check_env(env)
    
    print("✅ FleetEnv passes Stable Baselines3 environment checks")
    env.close()

if __name__ == "__main__":
    test_sb3_compatibility() 