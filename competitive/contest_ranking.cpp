#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef int long long;
int main()
{
    struct Player
    {
        string name;
        vector<char> status;
        int ac_count;
        int time_p;
    };
    
    int com_num;
    cin>>com_num;
    
    for(int z=0;z<com_num;z++)
    {
        int com_pep,com_que;
        cin>>com_pep>>com_que;
        
        Player men[com_pep];
        
        for(int i=0;i<com_pep;i++)
        {
            cin>>men[i].name;
            men[i].ac_count=0;
            men[i].time_p=0;
            men[i].status.resize(com_que);
            
            for(int j=0;j<com_que;j++)
            {
                string buf;
                cin>>buf;
                
                if(buf=="+")
                {
                    int x,y;
                    cin>>x>>y;
                    men[i].status[j]='+';
                    men[i].ac_count++;
                    men[i].time_p+=20*(x-1)+y;
                }
                else if(buf=="-")
                {
                    int x;
                    cin>>x;
                    men[i].status[j]='-';
                }
                else
                {
                    men[i].status[j]='.';
                }
            }
        }
        
        for(int i=0;i<com_pep-1;i++)
        {
            for(int j=0;j<com_pep-i-1;j++)
            {
                if(men[j].ac_count<men[j+1].ac_count)
                {
                    Player temp=men[j];
                    men[j]=men[j+1];
                    men[j+1]=temp;
                }
                else if(men[j].ac_count==men[j+1].ac_count&&men[j].time_p>men[j+1].time_p)
                {
                    Player temp=men[j];
                    men[j]=men[j+1];
                    men[j+1]=temp;
                }
            }
        }
        
        for(int i=0;i<com_pep;i++)
        {
            cout<<men[i].name<<" ";
            for(int j=0;j<com_que;j++)
            {
                cout<<men[i].status[j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}