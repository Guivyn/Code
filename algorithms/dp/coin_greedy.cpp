#include <iostream>
using namespace std;
int main()
{
    int n, tar;
    int coins[101]; // 从大到小储存硬币面额
    int dp[1001];   // 储存最小的硬币数量
    cin >> n >> tar;
    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }
    for (int i = 0; i <= tar; i++)
    {
        dp[i] = tar + 1;
    }
    dp[0] = 0;

    for (int i = 1; i <= tar; i++) // 遍历小于目标值的数
    {
        for (int j = 1; j <= n; j++) // 遍历硬币数
        {
            if (coins[j] <= i) // 如果当前硬币买呢小于等于当前目标值
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                // 选当前最小硬币数和上一个硬币面额下的最小硬币数
                // 相当于遍历每一个硬币面额下的上一个最小的硬币数
            }
        }
    }
    if (dp[tar] > tar)
        cout << "-1";
    else
        cout << dp[tar];
}