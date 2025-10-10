# EiRT-AscenD-Robotics

## Dronehive Master Box v0.1

### Compile

```bash
cd ros2_ws
colcon build --symlink-install
source install/setup.bash
ros2 run dronehive box_node
```

### Usage

##### Initialise a box

```bash
cd ros2_ws
source install/setup.bash
ros2 topic pub /dronehive/new_box_confirmed std_msgs/msg/Bool "data: true" -1
```

##### Deinitialize a box

> **NOTE:** Replace `<box_id>` with the actual box ID you want to deinitialize.
> The config is storeed in location `~/.config/dronehive/config.json`
> You can also find the box ID in the logs when you initialise the box.

```bash
cd ros2_ws
source install/setup.bash
ros2 topic pub /dronehive/deinitialise_box std_msgs/msg/String 'data: "<box_id>"' -1
```

