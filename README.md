# EiRT-AscenD-Robotics

## Dronehive Master Box v0.1

### Compile

```bash
cd ros2_ws
colcon build --symlink-install
source install/setup.bash
```

### Run

#### Run box nodes
```bash
# Master box
ros2 run dronehive box_node
# Slave box
ros2 run dronehive slave node
```

#### Run the nodes locally on your pc

The config files are originally located in `~/.config/dronehive` to make multiple boxes run on the same machine you need to change the this location. As on linux this location is indicated by `XDG_CONFIG_HOME` you just need to change it to a different location. Thus, see the example below:

```bash
ros2 run dronehive box_node
XDG_CONFIG_HOME=$HOME/delete ros2 run dronehive slave_node
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

##### GUI Dependendencies
```bash
sudo apt update
sudo apt install -y \
    libqt5charts5 libqt5charts5-dev \
    libqt5webkit5 libqt5webkit5-dev \
    libqt5webenginecore5 libqt5webenginewidgets5 qtwebengine5-dev \
    libqtdatavisualization5 libqtdatavisualization5-dev
```
