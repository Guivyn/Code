#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int num1;
    cin>>num1;
    for (int i = 0; i < num1; i++)
    {
        long long sum=0;
        int num2=0;
        int index=0;
        vector<int> data;
        cin>>num2;
        data.push_back(0);
        for (int i = 1; i <= num2; i++)//读取
        {
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        int max=0;
        for (int i = 1; i <= num2; i++)//选择并标记最大值
        {
            if (data[i]>max)
            {
                max=data[i];
                index=i;
            }
        }
        if (num2==1)
        {
            cout<<1+data[1]<<endl;
        }
        else if (index%2!=0)//如果奇数就直接输出
        {
            for (int i = 1; i <= num2; i=i+2)
            {
                sum++;
            }
            cout<<sum+data[index]<<endl;
        }
        else
        {
            long long sum1=0,sum2=0,max2=0;
            int max1=0;
            for (int i = 1; i <= num2; i=i+2)
            {
                sum1++;
                if (data[i] > max1) max1 = data[i];
            }
            for (int i = 2; i <= num2; i=i+2)
            {
                sum2++;
            }
            for (int i = 2; i <= num2; i=i+2)
            {
                if (data[i]>max2)
                {
                    max2=data[i];
                }
                
            }
            if (sum1+max1 > sum2+max2) 
            {
                cout<<sum1+data[index]<<endl;
            }
            else
            {
                cout<<sum2+max2<<endl;
            }
            }
        }
}