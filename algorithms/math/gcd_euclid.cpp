#include<iostream>
using namespace std;
int gcd (int a,int b)//辗转相除法
{
	return b?gcd(b,a%b):a;
}
int main()
{
    int num;
    int data[1001];
    scanf("%d",&num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&data[i]);
        if (data[i]==0)
        {
            continue;
        }
    }
    int ans=data[0];
    for (int i = 0; i < num-1; i++)
    {
        ans=gcd(ans,data[i+1]);
    }
    printf("%d",ans);
}