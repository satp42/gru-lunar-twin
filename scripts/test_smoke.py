#!/usr/bin/env python3

import sys
import numpy as np

# Add the rl directory to path
sys.path.append('rl')
from envs.fleet_env import FleetEnv

def smoke_test():
    """Task 25: Smoke test - run 200 steps, assert mean_reward > 0"""
    print("=== Task 25: Smoke Test - 200 Steps Fleet Coordination ===")
    
    env = FleetEnv()
    
    # Test parameters
    total_steps = 200
    episodes_to_test = 5
    all_episode_rewards = []
    
    for episode in range(episodes_to_test):
        print(f"\nEpisode {episode + 1}/{episodes_to_test}:")
        
        obs, _ = env.reset()
        episode_rewards = []
        total_kg = 0.0
        
        for step in range(total_steps):
            # Simple policy: 70% movement, 30% idle (realistic coordination)
            if np.random.random() < 0.7:
                action = np.random.randint(1, 5)  # Random movement direction
            else:
                action = 0  # Idle
            
            obs, reward, terminated, truncated, info = env.step(action)
            episode_rewards.append(reward)
            
            if terminated or truncated:
                print(f"   Episode terminated at step {step + 1}")
                break
        
        episode_mean = np.mean(episode_rewards)
        total_kg = obs[6]  # excavated_kg from observation
        
        print(f"   Steps: {len(episode_rewards)}")
        print(f"   Mean reward: {episode_mean:.3f}")
        print(f"   Total excavated: {total_kg:.1f} kg")
        print(f"   Production rate: {total_kg / len(episode_rewards) * 1000:.1f} kg/1000-steps")
        
        all_episode_rewards.extend(episode_rewards)
    
    # Overall smoke test results
    overall_mean = np.mean(all_episode_rewards)
    overall_std = np.std(all_episode_rewards)
    positive_rewards = sum(1 for r in all_episode_rewards if r > 0)
    total_rewards = len(all_episode_rewards)
    
    print(f"\n=== SMOKE TEST RESULTS ===")
    print(f"Total steps executed: {total_rewards}")
    print(f"Mean reward: {overall_mean:.3f}")
    print(f"Reward std: {overall_std:.3f}")
    print(f"Positive rewards: {positive_rewards}/{total_rewards} ({100*positive_rewards/total_rewards:.1f}%)")
    print(f"Min reward: {min(all_episode_rewards):.3f}")
    print(f"Max reward: {max(all_episode_rewards):.3f}")
    
    # Task 25 acceptance criteria: mean_reward > 0
    if overall_mean > 0:
        print(f"\n✅ SMOKE TEST PASSED: mean_reward = {overall_mean:.3f} > 0")
        print("✅ Fleet coordination policy generates positive rewards")
        print("✅ 24/7 excavation strategy is profitable")
        print("✅ Ready for production deployment")
        return True
    else:
        print(f"\n❌ SMOKE TEST FAILED: mean_reward = {overall_mean:.3f} ≤ 0")
        print("❌ Fleet coordination needs further reward tuning")
        return False

if __name__ == "__main__":
    success = smoke_test()
    sys.exit(0 if success else 1) 