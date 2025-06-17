import sys
sys.path.append('.')

import pytest
import rl.envs
import gymnasium as gym


def test_action_space_n_equals_5():
    """Test that FleetEnv action space has exactly 5 discrete actions"""
    env = gym.make('FleetEnv-v0')
    assert env.action_space.n == 5
    env.close()


def test_action_space_is_discrete():
    """Test that FleetEnv uses discrete action space"""
    env = gym.make('FleetEnv-v0')
    assert isinstance(env.action_space, gym.spaces.Discrete)
    env.close()


def test_observation_space_shape():
    """Test that FleetEnv observation space has correct shape"""
    env = gym.make('FleetEnv-v0')
    assert env.observation_space.shape == (7,)
    env.close() 