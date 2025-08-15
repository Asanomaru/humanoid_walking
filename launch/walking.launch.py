from launch import LaunchDescription
from launch_ros.actions import Node
from pathlib import Path

def generate_launch_description():
    params = str(Path(__file__).resolve().parent.parent / 'params' / 'walking.yaml')

    return LaunchDescription([
        Node(
            package='humanoid_walking',
            executable='humanoid_walking',
            name='humanoid_walking',
            output='screen',
            parameters=[params],
        ),
    ])
