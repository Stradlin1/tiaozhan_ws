#include <iostream>
#include <vector>
#include <string>

// 路径点结构体：定义机器人需要经过的单个点信息
struct Waypoint {
    double x;          
    double y;           
    double targetSpeed; 
    int waitTime;       
};

int main() {
    // 使用结构体数组/向量，定义一条完整的行驶路径
    std::vector<Waypoint> path = {
        {0.0, 0.0, 0.5, 1000},  // 起点
        {1.2, 0.5, 0.3, 0},     // 中转点 1
        {2.5, 1.8, 0.2, 500},   // 中转点 2
        {4.0, 0.0, 0.1, 2000}   // 终点
    };

    std::cout << "--- 机器人路径计划启动 ---" << std::endl;

    // 遍历路径点，模拟执行过程
    for (int i = 0; i < path.size(); ++i) {
        std::cout << "目标点 [" << i << "]: "
                  << "坐标(" << path[i].x << ", " << path[i].y << ") "
                  << "速度: " << path[i].targetSpeed << "m/s "
                  << "停留: " << path[i].waitTime << "ms" 
                  << std::endl;
    }

    return 0;
}