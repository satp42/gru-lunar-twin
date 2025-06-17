#!/usr/bin/env python3

import sys
sys.path.append('.')

import rl.envs
import gymnasium as gym
from stable_baselines3 import PPO
import os

def test_trained_model():
    """Test that the trained PPO model can be loaded and used"""
    
    # Check if model file exists
    if not os.path.exists("ppo.zip"):
        print("❌ ppo.zip not found")
        return False
    
    print("Loading trained PPO model...")
    env = gym.make("FleetEnv-v0")
    model = PPO.load("ppo", env=env)
    
    print("Testing model predictions...")
    obs, info = env.reset()
    
    for step in range(5):
        action, _states = model.predict(obs, deterministic=True)
        obs, reward, terminated, truncated, info = env.step(action)
        print(f"Step {step}: action={action}, reward={reward:.2f}")
        
        if terminated or truncated:
            obs, info = env.reset()
    
    env.close()
    print("✅ Trained model loaded and tested successfully")
    return True

if __name__ == "__main__":
    test_trained_model() 