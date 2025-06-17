#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory


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

    # RViz node (commented out for headless testing)
    # rviz_node = Node(
    #     package='rviz2',
    #     executable='rviz2',
    #     name='rviz2',
    #     output='screen'
    # )

    return LaunchDescription([
        robot_state_publisher_node,
        # rviz_node,  # Uncomment when running with GUI
    ]) 