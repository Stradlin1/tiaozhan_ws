#include <iostream>
#include <vector>
#include <string>
#include <memory>

// 传感器基类：定义统一接口
class Sensor {
protected:
    std::string sensorName;
public:
    Sensor(std::string name) : sensorName(name) {}
    virtual ~Sensor() {}
    // 纯虚函数：强制子类实现具体的数据读取逻辑
    virtual void readData() = 0; 
    std::string getName() { return sensorName; }
};
// 激光雷达：继承自 Sensor
class LidarSensor : public Sensor {
public:
    LidarSensor() : Sensor("激光雷达") {}
    void readData() override {
        std::cout << "[" << sensorName << "] 扫描结果：前方 1.5米 有障碍物。" << std::endl;
    }
};
// IMU惯导：继承自 Sensor
class ImuSensor : public Sensor {
public:
    ImuSensor() : Sensor("IMU惯导") {}
    void readData() override {
        std::cout << "[" << sensorName << "] 姿态结果：当前航向角为 90.5°。" << std::endl;
    }
};

int main() {
    // 使用基类指针统一管理不同类型的传感器
    std::vector<std::unique_ptr<Sensor>> robotSensors;
    robotSensors.push_back(std::make_unique<LidarSensor>());
    robotSensors.push_back(std::make_unique<ImuSensor>());
    std::cout << "--- 机器人传感器轮询启动 ---" << std::endl;
    // 多态调用：无需关心具体类型，统一调用接口
    for (const auto& sensor : robotSensors) {
        sensor->readData(); 
    }
    return 0;
}