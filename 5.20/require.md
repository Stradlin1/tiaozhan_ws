以下是为您提取的图片文字内容，保留了原始排版信息：

***

# 话题通信基本操作(C++)

**编写发布订阅实现，要求发布方以10HZ(每秒10次)的频率发布文本消息，订阅方订阅消息并将其消息内容打印输出。**

在模型实现中，ROS master 不需要实现，而连接的建立也已经被封装了，需要关注的关键点有三个：
1. 发布方
2. 接收方
3. 数据(此处为普通文本)

| 1.发布方 | 2.订阅方 |
| :--- | :--- |
| **实现流程：** | **实现流程：** |
| 1.包含头文件 | 1.包含头文件 |
| 2.初始化 ROS 节点:命名(唯一) | 2.初始化 ROS 节点:命名(唯一) |
| 3.实例化 ROS 句柄 | 3.实例化 ROS 句柄 |
| 4.实例化 发布者 对象 | 4.实例化 订阅者 对象 |
| 5.组织被发布的数据，并编写逻辑发布数据 | 5.处理订阅的消息(回调函数) |
| | 6.设置循环调用回调函数 |

以下是为您提取的图片文字内容，保留了原始排版逻辑：

***

# 话题通信

### **[ ROS Master ]**
**管理者**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;↗&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;↖
**注册：**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**注册：**
发布端信息、&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;订阅端信息、
话题信息&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;要订阅的话题

---

| **发布者 (节点1)** | **话题 topic** | **订阅者 (节点2)** |
| :--- | :---: | :--- |
| **节点名称：** talker | ————————> | **节点名称：** listener |
| **发布文本消息：** 你好啊 | **话题名称：** chatter | **订阅文本消息：** 你好啊 |
| **频率：** 每秒10次 | | **控制台打印：** 我听见你好啊 |

---

#### **代码实现流程：**

| **发布方步骤** | **订阅方步骤** |
| :--- | :--- |
| 1. 包含头文件 | 1. 包含头文件 |
| 2. 初始化 ROS 节点:命名(唯一) | 2. 初始化 ROS 节点:命名(唯一) |
| 3. 实例化 ROS 句柄 | 3. 实例化 ROS 句柄 |
| 4. 实例化 发布者 对象 | 4. 实例化 订阅者 对象 |
| 5. 组织被发布的数据，并编写逻辑发布数据 | 5. 处理订阅的消息(回调函数) |
| | 6. 设置循环调用回调函数 |