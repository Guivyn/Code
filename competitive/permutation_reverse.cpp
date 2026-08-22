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
        int n;
        cin >> n;
        
        vector<int> p(n);
        vector<int> pos(n + 1);
        
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }
        
        int cur = n;
        int idx = 0;
        
        while (idx < n && p[idx] == cur) {
            cur--;
            idx++;
        }
        
        if (idx < n) {
            int target = pos[cur];
            reverse(p.begin() + idx, p.begin() + target + 1);
        }
        
        for (int i = 0; i < n; i++) {
            cout << p[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}