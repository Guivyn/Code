#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<bool> canWin(n, false);

        for (int start = 0; start < n; start++)
        {
            vector<int> b = a;
            int total = 0;
            for (int x : b)
                total += x;

            int cur = start;
            int winner = -1;

            while (total > 0)
            {
                if (b[cur] > 0)
                {
                    b[cur]--;
                    total--;
                    if (total == 0)
                    {
                        winner = cur;
                        break;
                    }
                }
                cur = (cur + 1) % n;
            }
            if (winner != -1)
            {
                canWin[winner] = true;
            }
        }

        int ans = 0;
        for (bool w : canWin)
        {
            if (w)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}