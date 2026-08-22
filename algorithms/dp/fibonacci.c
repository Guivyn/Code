#include <stdio.h>

int main()
{
    long long a,n=2;
    long long dp[100];
    dp[0]=1;
    dp[1]=1;
    scanf("%lld",&a);
        while (1)
        {
            dp[n]=dp[n-1]+dp[n-2];
            if(dp[n]>9e18)
            break;
            n++;
        }
while (a--) {
        long long x;
        scanf("%lld", &x);
        
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == x) {
                found = 1;
                break;
            }
        }
        if (found)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        
    }
    
    return 0;
}