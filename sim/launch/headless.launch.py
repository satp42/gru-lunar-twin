#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    # Get the URDF file path
    urdf_file = os.path.join(
        os.path.dirname(__file__),
        '..',
        'models',
        'transport_rover',
        'transport_rover.urdf'
    )
    
    # Read URDF content
    with open(urdf_file, 'r') as file:
        robot_description_content = file.read()

    # Robot state publisher node
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description_content}]
    )

    return LaunchDescription([
        robot_state_publisher_node,
    ]) 