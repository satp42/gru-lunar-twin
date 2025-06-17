from gymnasium.envs.registration import register
from .fleet_env import FleetEnv

register(
    id='FleetEnv-v0',
    entry_point='rl.envs.fleet_env:FleetEnv',
    max_episode_steps=1000,
) 