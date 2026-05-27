# turtlepy

ROS Noetic Python example for controlling `turtlesim` so the turtle moves in a circle.

## Build

From the `5.27/turtlepy` workspace root, run `catkin_make` after sourcing ROS Noetic.

## Run

1. Source your ROS Noetic environment and workspace.
2. Launch the demo with one roslaunch command:

```bash
roslaunch turtlepy turtlepy.launch
```

This launches both `turtlesim_node` and the Python controller, so the turtle window opens directly. The turtle receives velocity commands on `/turtle1/cmd_vel`. The circle radius is approximately `linear_speed / angular_speed`.