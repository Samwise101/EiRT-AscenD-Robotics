from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='dronehive',
            executable='box_node',
            name='master_box',
            emulate_tty=True,
            output='screen',
        ),
        Node(
            package='dronehive',
            executable='dynamixel',
            name='dynamixel_controller',
            emulate_tty=True,
            output='screen',
        ),
    ])
