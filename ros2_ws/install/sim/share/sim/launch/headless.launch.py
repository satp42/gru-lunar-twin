#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    
    # Get path to world file
    world_file = PathJoinSubstitution([
        FindPackageShare('sim'),
        'worlds',
        'lunar_gravity_test.world'
    ])
    
    # Launch Gazebo headless (no GUI)
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'),
                'launch',
                'gz_sim.launch.py'
            ])
        ]),
        launch_arguments={
            'gz_args': ['-r -s --headless-rendering -v 4 ', world_file],
            'on_exit_shutdown': 'true'
        }.items()
    )
    
    # Simple timer node to shutdown after a few seconds (for testing)
    shutdown_timer = Node(
        package='sim',
        executable='shutdown_timer',
        name='shutdown_timer',
        output='screen',
        parameters=[{'timeout_seconds': 5.0}]
    )
    
    return LaunchDescription([
        gazebo,
        # Remove shutdown_timer for actual use - only for testing
    ]) 