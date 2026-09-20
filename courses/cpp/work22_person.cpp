#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    virtual void input()
    {
        cin >> name;
    }

    virtual void display()
    {
        cout << name << endl;
    }

    virtual ~Person() {} // 虚析构函数
};

class Student : public Person
{
private:
    char num[10];

public:
    void input()
    {
        cin >> num >> name;
    }

    void display()
    {
        cout << num << " " << name << endl;
    }
};

int main()
{
    Person *p;

    p = new Person;
    p->input();
    p->display();
    delete p;

    p = new Student;
    p->input();
    p->display();
    delete p;

    return 0;
}