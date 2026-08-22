#include <bits/stdc++.h>
using namespace std;

int main() {//字符频率统计与排序
    string s;
    cin >> s;

    array<int, 128> cnt = {0};
    for (char c : s) ++cnt[c];

    vector<pair<char, int>> vec;
    for (char c = '0'; c <= '9'; ++c) if (cnt[c]) vec.emplace_back(c, cnt[c]);
    for (char c = 'a'; c <= 'z'; ++c) if (cnt[c]) vec.emplace_back(c, cnt[c]);

    sort(vec.begin(), vec.end(),
        [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

    string ans;
    for (auto& p : vec) ans += p.first;
    cout << ans << endl;
    return 0;
}