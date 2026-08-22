#include<stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int data[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &data[i][j]);
        }
    }
    
    int count = 0;
    int results[40000][2];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int is_row_min = 1;
            int is_col_max = 1;
            
            for (int k = 0; k < m; k++) {
                if (data[i][k] < data[i][j]) {
                    is_row_min = 0;
                    break;
                }
            }
            
            for (int k = 0; k < n; k++) {
                if (data[k][j] > data[i][j]) {
                    is_col_max = 0;
                    break;
                }
            }
            
            if (is_row_min && is_col_max) {
                results[count][0] = i;
                results[count][1] = j;
                count++;
            }
        }
    }
    
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", results[i][0], results[i][1]);
    }
    
    return 0;
}