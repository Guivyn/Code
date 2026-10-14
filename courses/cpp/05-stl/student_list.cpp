#include<iostream>
#include<list>
using namespace std;
struct Student {
    int no;
    string name;
};
void Input(list<Student> &li)
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        Student m;
        cin >> m.no >> m.name;
        li.push_back(m);
    }
}

void Show(list<Student> &li)
{
    for (auto it = li.begin(); it != li.end(); it++)
    {
        cout << it->no << ", " << it->name << endl;
    }
}
int main()
{
    std::list<Student> li;

    Input(li); //输入
    Show(li); //输出

    return 0;
}