#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;
struct Student 
{
    int no;
    string name;
};

void Input(list<Student>& n)
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        Student exm;
        cin >> exm.no >> exm.name;
        n.push_back(exm);
    }
    
} 

void Show(list<Student>& n)
{
    for (auto it = n.begin(); it != n.end(); ++it)
    {
        cout << it->no << " " << it->name<<endl;
    }
    
}

int main()
{
    std::list<Student> li;

    Input(li); //输入
    Show(li); //输出

    return 0;
}