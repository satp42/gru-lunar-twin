#!/usr/bin/env python3

import sys
sys.path.append('.')

import rl.envs
import gymnasium as gym
from stable_baselines3 import PPO

def train_fleet_agent():
    """Train PPO agent on FleetEnv for 1k steps"""
    print("Creating FleetEnv...")
    env = gym.make("FleetEnv-v0")
    
    print("Initializing PPO model...")
    model = PPO("MlpPolicy", env, verbose=1)
    
    print("Training for 1000 timesteps...")
    model.learn(total_timesteps=1000)
    
    print("Saving model...")
    model.save("ppo")
    
    env.close()
    print("✅ Training complete. Model saved as ppo.zip")

if __name__ == "__main__":
    train_fleet_agent() 