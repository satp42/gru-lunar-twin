#!/usr/bin/env python3

import sys
import numpy as np

# Add the rl directory to path so we can import FleetEnv
sys.path.append('rl')
from envs.fleet_env import FleetEnv

def test_reward_shaping():
    """Test Task 27: Verify reward shaping produces positive mean rewards"""
    print("=== Task 27: Testing Reward Shaping ===")
    
    env = FleetEnv()
    
    # Test 1: Check reward components
    print("1. Testing reward components...")
    
    obs, _ = env.reset()
    
    # Test idle action (should be negative)
    obs, idle_reward, _, _, info = env.step(0)  # Idle
    print(f"   Idle reward: {idle_reward:.2f} (should be negative)")
    
    # Reset for movement test
    obs, _ = env.reset()
    
    # Test movement action (should be positive due to excavation)
    obs, move_reward, _, _, info = env.step(1)  # North movement
    print(f"   Movement reward: {move_reward:.2f} (should be positive)")
    print(f"   Excavation gained: {info['kg_gained']:.1f} kg")
    print(f"   Excavator active: {info['excavator_active']}")
    
    if move_reward > idle_reward:
        print("   ✅ Movement reward > idle reward")
    else:
        print("   ❌ Movement should be more rewarding than idle")
        return False
    
    # Test 2: Simulate episode with movement strategy
    print("\n2. Testing episode with movement strategy...")
    
    obs, _ = env.reset()
    total_reward = 0.0
    rewards = []
    
    # Run 50 steps mostly moving (simulates active coordination)
    for step in range(50):
        # 80% movement, 20% idle (realistic operation)
        if np.random.random() < 0.8:
            action = np.random.randint(1, 5)  # Random movement
        else:
            action = 0  # Idle
            
        obs, reward, terminated, truncated, info = env.step(action)
        total_reward += reward
        rewards.append(reward)
        
        if terminated:
            break
    
    mean_reward = total_reward / len(rewards)
    print(f"   Episodes rewards: min={min(rewards):.2f}, max={max(rewards):.2f}, mean={mean_reward:.2f}")
    print(f"   Total excavated: {obs[6]:.1f} kg")
    
    if mean_reward > 0:
        print("   ✅ Mean reward > 0 (Task 25 smoke test will pass)")
    else:
        print("   ❌ Mean reward still negative")
        return False
    
    # Test 3: Compare idle vs active strategies
    print("\n3. Comparing idle vs active strategies...")
    
    # Idle strategy
    obs, _ = env.reset()
    idle_rewards = []
    for _ in range(20):
        obs, reward, _, _, _ = env.step(0)  # Always idle
        idle_rewards.append(reward)
    idle_mean = np.mean(idle_rewards)
    
    # Active strategy  
    obs, _ = env.reset()
    active_rewards = []
    for _ in range(20):
        action = np.random.randint(1, 5)  # Always moving
        obs, reward, terminated, _, _ = env.step(action)
        active_rewards.append(reward)
        if terminated:
            break
    active_mean = np.mean(active_rewards)
    
    print(f"   Idle strategy mean reward: {idle_mean:.2f}")
    print(f"   Active strategy mean reward: {active_mean:.2f}")
    
    if active_mean > idle_mean:
        print("   ✅ Active strategy outperforms idle strategy")
    else:
        print("   ❌ Active strategy should outperform idle")
        return False
    
    print(f"\n✅ Task 27 COMPLETE: Reward shaping encourages fleet coordination")
    print(f"✅ Idle excavator penalty: Forces 24/7 operation")
    print(f"✅ Positive excavation rewards: Encourages productivity")
    print(f"✅ Mean reward > 0: Task 25 smoke test ready")
    
    return True

if __name__ == "__main__":
    success = test_reward_shaping()
    sys.exit(0 if success else 1) 