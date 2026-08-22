#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        unordered_map<int, int> freq;
        
        for (int i = 0; i < 2 * n; i++) 
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        int odd = 0, even = 0;
        
        unordered_map<int, int>::iterator it;
        for (it = freq.begin(); it != freq.end(); it++) 
        {
            if (it->second % 2 == 1) 
            odd++;
            else 
            even++;
        }
        
        int best = 0;//初始化
        
        best = min(even, n - odd);// 情况1：普通分配，奇数分配偶数，除非n不够大
        
        if (odd >= 2) // 情况2：奇数元素配对优化
        {
            int candidate = min(even, n - odd / 2);//剩余和偶数选个小的
            if (candidate > best) best = candidate;//如果情况更好则更新
        }
        
        if (odd == 0) // 情况3：没有奇数元素时的奇偶性调整
        {
            best = min(even, n);//防止偶数个数为4+
            if ((n - best) % 2 != 0 && best > 0) //分配完后剩余空间为奇数则best--
            {
                best--;
            }
        }
        
        cout << 2 * best + odd << '\n';//奇数+每组分配的偶数*2
    }
    
    return 0;
}