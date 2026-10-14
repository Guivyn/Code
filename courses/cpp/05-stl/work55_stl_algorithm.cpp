#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num1, num2;
    
    while (cin >> num1 >> num2)     
    {
        vector<int> n(num1);
        for (int i = 0; i < num1; i++)
        {
            cin >> n[i];
        }
        sort(n.begin(), n.end());
        
        for (int i = 0; i < num2; i++)
        {
            int temp;
            cin >> temp;
            auto it = lower_bound(n.begin(), n.end(), temp);
            if (it != n.end() && *it == temp)
                cout << temp << " found at " << (it - n.begin() + 1) << endl;
            else
                cout << temp << " not found" << endl;
        }
    }
    
    return 0;
}