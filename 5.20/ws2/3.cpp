#include <iostream> // 包含输入输出流库
using namespace std; // 定义一个结构体作为自定义数据类型

struct Person {
    string name;
    int age;
    double height;
};

int main() {
    // 初始化自定义数据类型的实例
    Person person1;
    person1.name = "Alice";
    person1.age = 30;
    person1.height = 165.5;

    // 输出自定义数据类型的实例及其成员变量的值
    cout << "姓名: " << person1.name << endl;
    cout << "年龄: " << person1.age << endl;
    cout << "身高: " << person1.height << " cm" << endl;

    system("pause");
    return 0;
}