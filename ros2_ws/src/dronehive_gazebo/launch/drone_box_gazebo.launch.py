import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable

from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    pkg_dronehive_gazebo = get_package_share_directory("dronehive_gazebo")
    gazebo_ros_pkg = get_package_share_directory("gazebo_ros")

    # -----------------------------
    #      robot_description
    # -----------------------------
    xacro_file = os.path.join(pkg_dronehive_gazebo, "urdf", "drone_box.xacro")

    robot_description = ParameterValue(
        Command([
            (
                "bash -c \"$(command -v xacro) '"
                f"{xacro_file}'"
                " | tail -n +2"
                " | perl -0777 -pe 's/<!--.*?-->//g'"
                " | tr -d '\\n'\""
            )
        ]),
        value_type=str,
    )

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="screen",
        parameters=[{"robot_description": robot_description}],
    )

    # -----------------------------
    #       Controllers YAML
    # -----------------------------
    controllers_yaml = os.path.join(
        pkg_dronehive_gazebo, "config", "drone_box_controllers.yaml"
    )

    # -----------------------------
    #      Gazebo (empty world)
    # -----------------------------
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(gazebo_ros_pkg, "launch", "gazebo.launch.py")
        ),
        launch_arguments={
            "world": os.path.join(gazebo_ros_pkg, "worlds", "empty.world"),
            "gui": "true",
            "verbose": "true",
        }.items(),
    )

    # -----------------------------
    #   Spawn the URDF in Gazebo
    # -----------------------------
    spawn_entity = Node(
        package="gazebo_ros",
        executable="spawn_entity.py",
        name="spawn_drone_box",
        output="screen",
        arguments=[
            "-topic", "robot_description",
            "-entity", "drone_box",
        ],
    )

    # -----------------------------
    #      Controller spawners
    # -----------------------------
    spawner_joint_state_broadcaster = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "joint_state_broadcaster",
            "--controller-manager", "/controller_manager",
            "--controller-manager-timeout", "120",
            "--param-file", controllers_yaml,
        ],
        output="screen",
    )

    spawner_door_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "door_controller",
            "--controller-manager", "/controller_manager",
            "--controller-manager-timeout", "120",
            "--param-file", controllers_yaml,
        ],
        output="screen",
    )

    # Delay controller spawning until the robot and controller_manager exist
    delayed_js_broadcaster = RegisterEventHandler(
        OnProcessExit(
            target_action=spawn_entity,
            on_exit=[spawner_joint_state_broadcaster],
        )
    )

    delayed_door_controller = RegisterEventHandler(
        OnProcessExit(
            target_action=spawner_joint_state_broadcaster,
            on_exit=[spawner_door_controller],
        )
    )

    return LaunchDescription([
        gazebo_launch,
        robot_state_publisher_node,
        spawn_entity,
        delayed_js_broadcaster,
        delayed_door_controller,
    ])
