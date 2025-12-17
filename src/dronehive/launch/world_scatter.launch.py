
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
        # both spellings
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


def _sample_positions(n: int, xmin: float, xmax: float, ymin: float, ymax: float, min_dist: float, rng: random.Random):
    pts = []
    tries = 0
    while len(pts) < n and tries < 30000:
        tries += 1
        x = rng.uniform(xmin, xmax)
        y = rng.uniform(ymin, ymax)
        if all((x - px) ** 2 + (y - py) ** 2 >= (min_dist ** 2) for (px, py) in pts):
            pts.append((x, y))
    return pts


def _launch_setup(context, *args, **kwargs):
    num_slaves = int(LaunchConfiguration("num_slaves").perform(context))
    num_drones = int(LaunchConfiguration("num_drones").perform(context))
    seed = int(LaunchConfiguration("seed").perform(context))
    xmin = float(LaunchConfiguration("xmin").perform(context))
    xmax = float(LaunchConfiguration("xmax").perform(context))
    ymin = float(LaunchConfiguration("ymin").perform(context))
    ymax = float(LaunchConfiguration("ymax").perform(context))
    min_dist = float(LaunchConfiguration("min_dist").perform(context))
    drone_altitude = float(LaunchConfiguration("drone_altitude").perform(context))
    circle_radius = float(LaunchConfiguration("circle_radius").perform(context))
    circle_speed = float(LaunchConfiguration("circle_speed").perform(context))

    rng = random.Random(seed)
    home_cfg = Path.home() / ".config"
    slave_ids = [f"slave_{i+1}" for i in range(num_slaves)]

    positions = _sample_positions(num_slaves, xmin, xmax, ymin, ymax, min_dist, rng)
    if len(positions) < num_slaves:
        raise RuntimeError(
            f"Could not sample {num_slaves} positions with min_dist={min_dist}. "
            "Try lowering min_dist or widening bounds."
        )

    mx = (xmin + xmax) / 2.0
    my = (ymin + ymax) / 2.0
    _write_config_dual(home_cfg, Path("."), _mk_master_payload(mx, my, 0.0, slave_ids))

    for sid, (x, y) in zip(slave_ids, positions):
        _write_config_dual(home_cfg, Path(sid), _mk_slave_payload(sid, x, y, 0.0))

    nodes = []
    nodes.append(LogInfo(msg=f"[SCATTER] Configs written; spawning {num_slaves} slaves"))

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

    centers = positions[: max(1, min(len(positions), num_drones))]
    for i in range(num_drones):
        drone_id = f"drone{i+1}"
        cx, cy = centers[i % len(centers)]
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
                "--altitude", str(drone_altitude + 0.2 * i),
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
        DeclareLaunchArgument("num_slaves", default_value="50"),
        DeclareLaunchArgument("num_drones", default_value="50"),
        DeclareLaunchArgument("seed", default_value="7"),
        DeclareLaunchArgument("xmin", default_value="-6.0"),
        DeclareLaunchArgument("xmax", default_value="6.0"),
        DeclareLaunchArgument("ymin", default_value="-10.0"),
        DeclareLaunchArgument("ymax", default_value="0.0"),
        DeclareLaunchArgument("min_dist", default_value="1.0"),
        DeclareLaunchArgument("drone_altitude", default_value="2.0"),
        DeclareLaunchArgument("circle_radius", default_value="1.0"),
        DeclareLaunchArgument("circle_speed", default_value="0.35"),
        DeclareLaunchArgument(
            "rviz_config",
            default_value=PathJoinSubstitution([FindPackageShare("dronehive"), "rviz", "dronehive_markers.rviz"]),
        ),
        OpaqueFunction(function=_launch_setup),
    ])
