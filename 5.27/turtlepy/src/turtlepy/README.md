# turtlepy

中文：

- 本包为 ROS Noetic 的 Python 示例，演示如何控制 `turtlesim` 中的小乌龟做圆周运动。
- 构建：在工作区根目录 `5.27/turtlepy` 下执行：

```bash
source /opt/ros/noetic/setup.bash
cd /home/matthew-xie/tiaozhan_ws/5.27/turtlepy
catkin_make
source devel/setup.bash
```

- 运行（一键启动显示与控制）：

```bash
roslaunch turtlepy turtlepy.launch
```

- 也可拆开运行：先启动显示，再启动控制节点：

```bash
rosrun turtlesim turtlesim_node
rosrun turtlepy circle_motion.py
```

- 小乌龟接收的速度话题为 `/turtle1/cmd_vel`，圆周半径约为 `linear_speed / angular_speed`。

English:

- Python example for ROS Noetic demonstrating circular motion control of `turtlesim`.
- Build from the workspace root `5.27/turtlepy`:

```bash
source /opt/ros/noetic/setup.bash
cd /home/matthew-xie/tiaozhan_ws/5.27/turtlepy
catkin_make
source devel/setup.bash
```

- Run (single-command launch to start both display and controller):

```bash
roslaunch turtlepy turtlepy.launch
```

- Or run separately (start display then the controller):

```bash
rosrun turtlesim turtlesim_node
rosrun turtlepy circle_motion.py
```

- The controller publishes velocity on `/turtle1/cmd_vel`. Approximate circle radius is `linear_speed / angular_speed`.