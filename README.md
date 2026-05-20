# tiaozhan_ws

[English](#english) | [中文](#chinese)

---

<a name="english"></a>
## English

This repository contains the code for the **"Challenge Project"** of the freshman Robot Engineering program at **Northeastern University (NEU)**. It is primarily used for introductory ROS programming tutorials and practice, while also serving as a personal project for learning Git version control and GitHub hosting.

### Development Environment
- **OS**: Ubuntu 20.04
- **ROS**: ROS Noetic

### Directory Structure
The repository is organized by date, with each date folder containing one or more catkin workspaces.

**Example:**
```text
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
**Logic**: Folders are categorized by date (e.g., `5.13`, `5.20`), and within each date directory, workspaces are named `ws1`, `ws2`, etc. Each `ws*` is a standard catkin workspace.

### Quick Start
1. Install and configure ROS Noetic.
2. Navigate to the target workspace and build:
   ```bash
   cd 5.13/ws1
   catkin_make
   source devel/setup.bash
   ```
3. Execute nodes or launch files:
   ```bash
   roslaunch <package> <file.launch>
   rosrun <package> <node>
   ```

### Version Control Guidelines
- Use feature branches (`feature/*` or `fix/*`) for development.
- Maintain concise and descriptive commit messages.
- Regularly synchronize with the remote repository using the `pull` $\rightarrow$ `add` $\rightarrow$ `commit` $\rightarrow$ `push` workflow.

**Developer:** Matthew Xie, Northeastern University

---

<a name="chinese"></a>
## 中文

本仓库为**东北大学（NEU）**机器人工程专业大一**“挑战课题”**的代码存储库，旨在用于 ROS 编程入门教学与练习。同时，本仓库亦作为学习 Git 版本管理与 GitHub 托管的实践项目。

### 开发环境
- **操作系统**: Ubuntu 20.04
- **ROS 版本**: ROS Noetic

### 目录结构说明
本仓库采用按日期组织目录，每个日期文件夹下包含一个或多个 catkin 工作区。

**示例：**
```text
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
**组织逻辑**：顶层目录按日期（如 `5.13`, `5.20`）区分，日期目录下按 `ws1`, `ws2` 等命名具体工作区。每个 `ws*` 均为标准的 catkin 工作区。

### 快速开始
1. 安装并配置 ROS Noetic。
2. 进入目标工作区并构建：
   ```bash
   cd 5.13/ws1
   catkin_make
   source devel/setup.bash
   ```
3. 运行节点或 launch 文件：
   ```bash
   roslaunch <package> <file.launch>
   rosrun <package> <node>
   ```

### 版本管理规范
- 建议使用功能分支（`feature/*` 或 `fix/*`）进行开发。
- 提交信息（Commit Message）应保持简洁且具有描述性。
- 遵循 `pull` $\rightarrow$ `add` $\rightarrow$ `commit` $\rightarrow$ `push` 的标准流程，定期同步远程仓库。

**开发者**：淑暗霖 (Matthew Xie)，东北大学
```

