# tiaozhan_ws

这是东北大学（NEU）机器人工程大一“挑战课题”的代码仓库，用于 ROS 编程入门教学与练习。仓库同时作为我学习代码版本管理与 GitHub 托管的练习项目。

## 开发环境
- 操作系统：Ubuntu 20.04
- ROS 版本：ROS Noetic

## 目录结构说明
本仓库的顶层按日期命名，每个日期目录中包含一个或多个 catkin 工作区。结构示例：

```
5.13/
	ws1/
		src/
		build/
		devel/
	ws2/
		src/
		build/
		devel/
5.20/
	ws1/
		src/
		build/
		devel/
```

也就是说：先按日期（例如 `5.13`, `5.20`）区分，然后在每个日期目录下按 `ws1/`, `ws2/` 等命名各自的工作区。

每个 `ws*` 工作区为典型的 catkin 工作区，包含 `src/`、`build/`、`devel/` 等目录，用法与标准 ROS 工作区一致。

## 快速开始
1. 安装并配置 ROS Noetic（参考官方教程）。
2. 进入对应的工作区（例如某个日期目录下的 `ws1`）并构建：

```bash
cd 5.13/ws1
catkin_make
source devel/setup.bash
```

3. 运行节点或 launch 文件（示例）：

```bash
roslaunch <package> <file.launch>
rosrun <package> <node>
```

## 版本管理与协作
- 建议使用分支开发（feature/* 或 fix/*），提交信息保持简洁且描述性。
- 记得常规 `git pull`、`git add`、`git commit`、`git push` 流程并定期同步远程仓库。

## 后续
---
开发者：东北大学 淑暗霖