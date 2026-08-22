#include <stdio.h>

int main()
{
    int n,t,s;
    int i=1;
    int first=1;

    scanf("%d",&n);

    while(i<n)
    {
    first*=10;
    i++;
    }

    i=first;

    while(i<first*10)
    {
        int sum=0;
        t=i;
        do
        {
        s=t%10;
        t/=10;
        int d=1;
        for(int j=0; j<n; j++)
        {
            d*=s;
        }
        sum+=d;
        }while(t>0);

    if(sum==i)
    {
        printf("%d\n",i);
    }
    i++;
    }
    return 0;
}