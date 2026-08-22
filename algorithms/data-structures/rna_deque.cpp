#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    int num1;
    char data[10005];                  
    scanf("%d", &num1);
    scanf("%s", data);              
    
    deque<char> ori;
    for (int i = 0; i < num1; i++)       
    {
        ori.push_back(data[i]);
    }
    
    int num2;
    scanf("%d", &num2);
    
    for (int i = 1; i <= num2; i++)
    {
        int temp;
        scanf("%d", &temp);
        
        if (temp == 1)                 
        {
            int l, r, p;
            scanf("%d%d%d", &l, &r, &p);
            
            l--, r--, p--;
            
            deque<char> segment;
            for (int j = l; j <= r; j++)
            {
                segment.push_back(ori[j]);
            }

            ori.insert(ori.begin() + p + 1, segment.begin(), segment.end());
            
        }
        else if (temp == 2)             
        {
            int l, r, c;
            scanf("%d%d%d", &l, &r, &c);
            
            l--, r--;                   
            
            if (c % 2 == 1)            
            {
                reverse(ori.begin() + l, ori.begin() + r + 1);
            }

        }
        else if (temp == 3)            
        {
            int l, r;
            scanf("%d%d", &l, &r);
            
            l--, r--;             
            
            ori.erase(ori.begin() + l, ori.begin() + r + 1);
        }
    }
    
    for (size_t j = 0; j < ori.size(); j++)
    {
        printf("%c", ori[j]);
    }
    printf("\n");
    
    return 0;
}