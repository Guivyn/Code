#include<stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    int arr1[n], arr2[m];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    
    for (int i = 0; i < m; i++) {
        int target = arr2[i];
        int left = 0;
        int right = n - 1;
        int found = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr1[mid] == target) {
                found = mid + 1;  
                break;
            } else if (arr1[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        printf("%d\n", found);
    }
    
    return 0;
}