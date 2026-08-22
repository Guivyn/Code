#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll fastPow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

const int MAXN = 5005;
ll E[MAXN][MAXN];
ll inv[10005];

void precompute()
{
    for (int i = 1; i <= 10000; i++) {
        inv[i] = fastPow(i, mod-2, mod);
    }
    
    // 边界条件
    for (int a = 0; a <= 5000; a++) E[a][0] = a;
    for (int b = 0; b <= 5000; b++) E[0][b] = b;
    
    // DP
    for (int a = 1; a <= 5000; a++) {
        for (int b = 1; b <= 5000; b++) {
            if (a >= b) {
                E[a][b] = (a * inv[a + b] % mod * (1 + E[a - 1][b]) % mod
                         + b * inv[a + b] % mod * E[a][b - 1] % mod) % mod;
            } else {
                E[a][b] = (b * inv[a + b] % mod * (1 + E[a][b - 1]) % mod
                         + a * inv[a + b] % mod * E[a - 1][b] % mod) % mod;
            }
        }
    }
}

void solve() {
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << E[n][m] << endl;
    }
}

int main() {
    solve();
    return 0;
}