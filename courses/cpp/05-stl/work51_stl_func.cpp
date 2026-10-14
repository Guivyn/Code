#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
    string n;
    cin >> n;
    sort(n.begin(),n.end(), greater<char>());
    cout << n;
}