#include<stdio.h>

typedef struct 
{
    char num[20];
    char name[80];
    float price;
}Book;

int main()
{
    Book book[100];
    int n = 0;
    while(scanf("%s %s %f",book[n].num,book[n].name,&book[n].price)==3)
    {
        n++;
    }

    printf("书号 书名 价格\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s %s %.2f\n", book[i].num, book[i].name, book[i].price);
    }
    
}