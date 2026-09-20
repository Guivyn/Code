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
    Book insert;
    int pos;
    int n = 1;
    scanf("%d",&pos);
    scanf("%s %s %f", insert.num, insert.name, &insert.price);
    while(scanf("%s %s %f",book[n].num,book[n].name,&book[n].price)==3)
    {
        n++;
    }

    for (int i = n; i >=  pos; i--)
    {
        book[i+1] = book[i];
    }
    book[pos] = insert;

    printf("书号 书名 价格\n");

    for (int i = 1; i <= n; i++)
    {
        printf("%s %s %.2f\n", book[i].num, book[i].name, book[i].price);
        
    }
    
}