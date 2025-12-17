
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import random
from pathlib import Path

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, LogInfo
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution

def _write_config_dual(home_dir: Path, rel_xdg: Path, payload: dict) -> None:
    """Write config.json in BOTH expected locations for DroneHive."""
    xdg_root = home_dir / rel_xdg
    xdg_root.mkdir(parents=True, exist_ok=True)

    dh_dir = xdg_root / "dronehive"
    dh_dir.mkdir(parents=True, exist_ok=True)
    (dh_dir / "config.json").write_text(json.dumps(payload, indent=2))

    (xdg_root / "config.json").write_text(json.dumps(payload, indent=2))


def _pos_dict(x: float, y: float, z: float) -> dict:
    return {"lat": float(x), "lon": float(y), "elv": float(z)}


def _mk_master_payload(x: float, y: float, z: float, slave_ids) -> dict:
    pos = _pos_dict(x, y, z)
    return {
        "box_id": "master",
        "drone_id": "",
        "initialised": True,
        "landing_position": dict(pos),
        "lending_position": dict(pos),
        "linked_box_ids": list(slave_ids),
    }


def _mk_slave_payload(slave_id: str, x: float, y: float, z: float) -> dict:
    pos = _pos_dict(x, y, z)
    return {
        "box_id": slave_id,
        "drone_id": "",
        "initialised": True,
        "landing_position": dict(pos),
        "lending_position": dict(pos),
        "linked_box_ids": [],
    }


def _launch_setup(context, *args, **kwargs):
    num_slaves = int(LaunchConfiguration("num_slaves").perform(context))
    num_drones = int(LaunchConfiguration("num_drones").perform(context))
    spacing = float(LaunchConfiguration("spacing").perform(context))
    base_x = float(LaunchConfiguration("base_x").perform(context))
    base_y = float(LaunchConfiguration("base_y").perform(context))
    drone_altitude = float(LaunchConfiguration("drone_altitude").perform(context))
    circle_radius = float(LaunchConfiguration("circle_radius").perform(context))
    circle_speed = float(LaunchConfiguration("circle_speed").perform(context))

    home_cfg = Path.home() / ".config"
    slave_ids = [f"slave_{i+1}" for i in range(num_slaves)]

    _write_config_dual(home_cfg, Path("."), _mk_master_payload(base_x, base_y, 0.0, slave_ids))

    for i, sid in enumerate(slave_ids):
        x = base_x - (spacing * (num_slaves - 1) / 2.0) + i * spacing
        y = base_y
        _write_config_dual(home_cfg, Path(sid), _mk_slave_payload(sid, x, y, 0.0))

    nodes = []
    nodes.append(LogInfo(msg=f"[ROW] Master config: {home_cfg/'dronehive'/'config.json'}"))
    nodes.append(LogInfo(msg=f"[ROW] Slave configs: ~/.config/<slave_id>/(dronehive/config.json + config.json)"))

    nodes.append(Node(
        package="dronehive",
        executable="box_node",
        name="box_node_master",
        namespace="box/master",
        output="screen",
        additional_env={"XDG_CONFIG_HOME": str(home_cfg)},
    ))

    for sid in slave_ids:
        nodes.append(Node(
            package="dronehive",
            executable="slave_node",
            name=f"slave_node_{sid}",
            namespace=f"box/{sid}",
            output="screen",
            additional_env={"XDG_CONFIG_HOME": str(home_cfg / sid)},
        ))

    cols = max(1, min(num_slaves, 6))
    for i in range(num_drones):
        drone_id = f"drone{i+1}"
        col = i % cols
        row_i = i // cols
        cx = base_x + (col - (cols - 1) / 2.0) * (2.8 * circle_radius + 0.6)
        cy = base_y + 3.0 + row_i * (2.8 * circle_radius + 0.6)

        nodes.append(Node(
            package="offboard",
            executable="offboard",
            name=f"offboard_{drone_id}",
            namespace=f"drone/{drone_id}",
            output="screen",
            arguments=[
                "--drone-id", drone_id,
                "--start-x", str(cx),
                "--start-y", str(cy),
                "--altitude", str(drone_altitude + 0.25 * i),
                "--circle-radius", str(circle_radius),
                "--circle-speed", str(circle_speed),
            ],
        ))

    nodes.append(Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", LaunchConfiguration("rviz_config")],
    ))

    return nodes


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("num_slaves", default_value="6"),
        DeclareLaunchArgument("num_drones", default_value="3"),
        DeclareLaunchArgument("spacing", default_value="1.6"),
        DeclareLaunchArgument("base_x", default_value="2.0"),
        DeclareLaunchArgument("base_y", default_value="-5.0"),
        DeclareLaunchArgument("drone_altitude", default_value="2.0"),
        DeclareLaunchArgument("circle_radius", default_value="1.0"),
        DeclareLaunchArgument("circle_speed", default_value="0.35"),
        DeclareLaunchArgument(
            "rviz_config",
            default_value=PathJoinSubstitution([FindPackageShare("dronehive"), "rviz", "dronehive_markers.rviz"]),
        ),
        OpaqueFunction(function=_launch_setup),
    ])
