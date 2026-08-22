#include <stdio.h>
#include <string.h>

#define MAXN 1005

char grid[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m, a, b;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, char type) {
    vis[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == type) {
            dfs(nx, ny, type);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &a, &b);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    
    memset(vis, 0, sizeof(vis));
    
    int desk_cnt = 0, chair_cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                if (grid[i][j] == '#') {
                    desk_cnt++;
                    dfs(i, j, '#');
                } else if (grid[i][j] == '^') {
                    chair_cnt++;
                    dfs(i, j, '^');
                }
            }
        }
    }
    
    long long ans = (long long)desk_cnt * a + (long long)chair_cnt * b;
    printf("%lld\n", ans);
    
    return 0;
}