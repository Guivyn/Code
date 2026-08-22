#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(k), b(k);
        for (int i = 0; i < k; i++) cin >> a[i];
        for (int i = 0; i < k; i++) cin >> b[i];

        // 处理每个查询
        while (q--) {
            int d;
            cin >> d;

            // 如果 d 为 0，时间就是 0
            if (d == 0) {
                cout << "0 ";
                continue;
            }

            // 找到 d 所在的星段
            int idx = lower_bound(a.begin(), a.end(), d) - a.begin();
            
            int start_pos, start_time;
            if (idx == 0) {
                start_pos = 0;
                start_time = 0;
            } else {
                start_pos = a[idx - 1];
                start_time = b[idx - 1];
            }
            
            int end_pos = a[idx];
            int end_time = b[idx];
            
            // 计算时间
            long long dist = end_pos - start_pos;
            long long time_diff = end_time - start_time;
            long long delta = d - start_pos;
            
            // 使用整数运算避免浮点数误差
            long long time = start_time + (delta * time_diff) / dist;
            cout << time << " ";
        }
        cout << "\n";
    }

    return 0;
}