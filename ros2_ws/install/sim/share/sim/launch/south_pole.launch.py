#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    
    # Get path to south_pole world file
    world_file = PathJoinSubstitution([
        FindPackageShare('sim'),
        'worlds',
        'south_pole.world'
    ])
    
    # Launch Gazebo headless with south_pole world
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
    
    return LaunchDescription([
        gazebo
    ]) 