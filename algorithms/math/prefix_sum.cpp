#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int num_long;
    vector<int> data;
    vector<int> Prefix_Sum;
    cin>>num_long;
    for (int i = 0; i < num_long; i++)
    {
        int temp;
        cin>>temp;
        data.push_back(temp);
    }
    Prefix_Sum.push_back(0); 
    for (int i = 0; i < num_long; i++)
    {
        int temp=data[i]+Prefix_Sum[i];
        Prefix_Sum.push_back(temp);
    }
    int num2_long;
    cin>>num2_long;
    for (int i = 0; i < num2_long; i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        int sum=0;
        sum=Prefix_Sum[temp2]-Prefix_Sum[temp1-1];
        cout<<sum<<endl;
    }
}