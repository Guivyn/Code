#include<stdio.h>

int main()
{
    printf("请输入数字(0~100),-1作为输入结束,请输入小于100个数: ");
    
    typedef struct frequency
    {
        int number;  
        int count;   
    } frequency;
    
    frequency data[101]; 
    

    for (int i = 0; i <= 100; i++)
    {
        data[i].number = i;
        data[i].count = 0;
    }
    

    while(1)
    {
        int temp;
        scanf("%d", &temp);
        if (temp == -1)
        {
            break;
        }
        if (temp >= 0 && temp <= 100)
        {
            data[temp].count++;
        }
    }
    

    printf("数字   频率\n");
    for (int i = 0; i <= 100; i++)
    {
        if (data[i].count == 0)
        {
            continue;
        }
        printf("%-8d%-8d\n", data[i].number, data[i].count);
    }
    

    for (int i = 0; i < 100; i++) 
    {
        for (int j = 0; j < 100 - i; j++) 
        {
            if (data[j].count < data[j + 1].count)
            {
                frequency temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    
    printf("\n按频率排序后:\n");
    printf("数字   频率\n");
    for (int i = 0; i <= 100; i++)
    {
        if (data[i].count == 0)
        {
            continue;
        }
        printf("%-8d%-8d\n", data[i].number, data[i].count);
    }
    
    return 0;
}