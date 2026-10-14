#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int m;
    cin >> m;
    vector<string> n(m);
    for (int i = 0; i < m; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < m; i++)
    {
        sort(n[i].begin(), n[i].end());
    }
    sort(n.begin(), n.end(), greater<string>());
    for (int i = 0; i < m; i++)
    {
        cout << n[i]<<endl;
    }
    
}