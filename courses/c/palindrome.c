#include<stdio.h>
#include<string.h>
int main()
{
    int num;
    char data[1001];
    char copy[1001]="";
    scanf("%d",&num);
    getchar();
    for (int i = 0; i < num; i++)
    {
        fgets(data,sizeof(data),stdin);
        data[strcspn(data, "\n")] = '\0';
        int len = strlen(data);
        int is_palindrome = 1; 
        for (int j = 0; j < len / 2; j++) 
        {
            if (data[j] != data[len - j - 1])  
            {
                is_palindrome = 0;
                break;
            }
        }
        if (is_palindrome)  
        {
            if (strlen(copy) == 0)  
            {
                strcpy(copy, data);
            }
            else
            {
                if (strlen(data) > strlen(copy) || (strlen(data) == strlen(copy) && strcmp(data, copy) > 0))
                {
                    strcpy(copy, data);
                }
            }
        }
        if (i==num-1)
        {
            printf("%s\n", copy); 
        }
    }
}