#!/usr/bin/env python3

import sys
sys.path.append('.')

import rl.envs
import gymnasium as gym

def main():
    """Example usage of FleetEnv"""
    env = gym.make('FleetEnv-v0')
    
    observation, info = env.reset(seed=42)
    print(f"Initial observation: {observation}")
    
    for step in range(10):
        action = env.action_space.sample()
        observation, reward, terminated, truncated, info = env.step(action)
        print(f"Step {step}: action={action}, reward={reward:.2f}, obs={observation}")
        
        if terminated or truncated:
            print("Episode ended")
            observation, info = env.reset()
    
    env.close()

if __name__ == "__main__":
    main() 