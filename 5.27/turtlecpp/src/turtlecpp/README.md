# turtlecpp

ROS Noetic C++ example for controlling `turtlesim` so the turtle moves in a circle.

## Build

From the `5.27/turtlecpp` workspace root, run `catkin_make` after sourcing ROS Noetic.

## Run

1. Source your ROS Noetic environment and workspace.
2. Launch the demo:

```bash
roslaunch turtlecpp circle_motion.launch
```

The turtle receives velocity commands on `/turtle1/cmd_vel`. The circle radius is approximately `linear_speed / angular_speed`.