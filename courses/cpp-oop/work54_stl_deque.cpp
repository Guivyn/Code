#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    deque<int> m;
    for (int i = 1; i <= n; i++)
    {
        m.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << m.front();
        m.pop_front();
        int num;
        num = m.front();
        m.pop_front();
        m.push_back(num);
        cout << " ";
    }
    
}