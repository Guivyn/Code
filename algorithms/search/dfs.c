#include<stdio.h>

void dfs(int n,int m);

int n,m;
int data[100];

int main()
{
    scanf("%d%d",&n,&m);
    dfs(1,0);
}

void dfs(int start,int depth)
{
    if (depth==n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = start; i <= m; i++)
    {
        data[depth] = i; 
        dfs(i+1,depth+1);
    }
}