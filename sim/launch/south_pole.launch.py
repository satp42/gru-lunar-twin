from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    # Get the world file path
    world_file = PathJoinSubstitution([
        FindPackageShare('gru_lunar_twin'),
        'sim', 'worlds', 'south_pole.world'
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            'world_file',
            default_value=world_file,
            description='Path to the world file'
        ),
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    FindPackageShare('ros_gz_sim'),
                    'launch',
                    'gz_sim.launch.py'
                ])
            ]),
            launch_arguments={
                'gz_args': LaunchConfiguration('world_file')
            }.items(),
        ),
    ]) 