#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num1, num2;
    while (cin >> num1)
    {
        cin >> num2;
        int arr[num1];
        for (int i = 0; i < num1; i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+num1);
        for (int i = 0; i < num2; i++)
        {
            int temp;
            cin >> temp;
            int* pos = lower_bound(arr, arr + num1, temp);
            if (pos != arr + num1 && *pos == temp)
            {
                // 输出 1-based 索引
                cout << temp << " found at " << (pos - arr + 1) << endl;
            }
            else
            {
                cout << temp << " not found " << endl;
            }
        }
    }
}