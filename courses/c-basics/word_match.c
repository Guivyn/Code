#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int num=0;
    int fir=-1;
    char ori[100];
    char data[1008];

    fgets(ori,sizeof(ori),stdin);
    fgets(data,sizeof(data),stdin);

    ori[strcspn(ori, "\n")] = '\0';
    data[strcspn(data, "\n")] = '\0';

    int ori_len=strlen(ori); 
    int data_len=strlen(data); 

    for (int i = 0; i <= data_len - ori_len;  i++)
    {
        int match = 1;
        if ((i == 0 || data[i-1] == ' ') && (i + ori_len == data_len || data[i + ori_len] == ' '))
        {
            for (int j = 0; j < ori_len; j++)
            {
                if (tolower(ori[j]) != tolower(data[i + j]))
                {
                    match = 0;
                    break;
                }
            }
        }
        else
        {
            match = 0;  
        }

        if (match)
        {
            num++;
            if (fir==-1)
            {
                fir=i;
            }
        }
    }
    
    if (num > 0)
    {
        printf("%d %d", num, fir);
    }
    else
    {
        printf("-1");
    }
}
