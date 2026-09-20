#include<stdio.h>

typedef struct 
{
    char num[20];
    char name[80];
    float price;
}Book;

int main()
{
    int n = 0;
    Book book[100];

    int type;
    scanf("%d", &type);

    if (type==1)
    {
        int kind;
        scanf("%d",&kind);

        while(scanf("%s %s %f",book[n].num,book[n].name,&book[n].price)==3)
        {
            n++;
        }

        printf("%s %s %.2f\n", book[kind-1].num, book[kind-1].name, book[kind-1].price);
    }
    
    if (type==2)
    {
        char name_search[20];
        scanf("%s",name_search);

        while(scanf("%s %s %f",book[n].num,book[n].name,&book[n].price)==3)
        {
            n++;
        }

        int check = 0;

        for(int i = 0; i < n; i++)
        {
            if (strcmp(book[i].name,name_search)==0)
            {
                printf("%s %s %.2f\n", book[i].num, book[i].name, book[i].price);
                check++;
            }
        }
        if (check==0)
        {
            printf("未找到\n");
        }
    }
}