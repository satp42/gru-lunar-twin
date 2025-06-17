#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, Command
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    
    # Get path to URDF file
    urdf_file = PathJoinSubstitution([
        FindPackageShare('sim'),
        'urdf',
        'transport_rover.urdf'
    ])
    
    # Read the URDF file content
    robot_description_content = Command(['cat ', urdf_file])
    
    return LaunchDescription([
        # Robot State Publisher - publishes robot transforms and robot_description
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': robot_description_content,
                'use_sim_time': False
            }]
        ),
        
        # Test to verify the URDF file exists and is readable
        ExecuteProcess(
            cmd=['echo', 'Testing URDF file path:'],
            output='screen'
        ),
        
        ExecuteProcess(
            cmd=['ls', '-la', urdf_file],
            output='screen'
        )
    ]) 