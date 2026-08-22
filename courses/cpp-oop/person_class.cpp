#include <iostream>
#include <cstring> // strcpy, strlen
using namespace std;

class Person
{
private:
    int id;
    char *name; // 指针成员，用于动态存储姓名
public:
    // 普通构造函数
    Person(int i, const char *n)
    {
        id = i;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "调用构造函数, name=" << name << endl;
    }

    Person(Person &p)
    {
        id = p.id;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }

    // 析构函数
    ~Person()
    {
        cout << "调用析构函数, name=" << name << endl;
        delete[] name;
    }

    void show()
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main()
{
    Person p1(101, "Alice");
    Person p2(p1); // 用p1初始化p2

    p1.show();
    p2.show();
    return 0;
}