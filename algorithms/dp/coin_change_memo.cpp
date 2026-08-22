#include <bits/stdc++.h>
using namespace std;

vector<int> memo;                    // 用来记住已经算过的答案

// 递归函数：用 coins 这些硬币，凑出 amount 最少需要几枚？
int dp(const vector<int>& coins, int amount) {
    if (amount == 0) return 0;            // 金额为0，不需要任何硬币
    if (amount < 0) return -1;           // 金额变成负数，不可能，失败

    if (memo[amount] != -1)              // 之前算过，直接用结果
        //← 记忆化！
        return memo[amount];

    int ans = 999999;                    // 先假设要很多很多枚（一个很大数）

    for (int coin : coins) {             // 试试每一种硬币
        int res = dp(coins, amount - coin);  // 用了这枚硬币后，剩下多少钱？
        if (res >= 0) {                  // 剩下能凑出来
            ans = min(ans, res + 1);     // 总枚数 = 剩下的枚数 + 当前这1枚
        }
    }

    memo[amount] = (ans == 999999 ? -1 : ans);  // 存下结果：没变说明凑不出→-1
    return memo[amount];
}

int main() {
    // 下面这两行是“提速代码”，可以让 cin 变快10倍！
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n, amount;
    cin >> n >> amount;                  // 输入：几种硬币？目标金额？

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];                 // 输入每种硬币的面值
    }

    memo = vector<int>(amount + 1, -1);  // -1 表示“还没算过”

    int result = dp(coins, amount);
    cout << result << endl;              // 输出答案

    return 0;
}