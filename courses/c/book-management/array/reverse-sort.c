#include<stdio.h>

typedef struct 
{
    char num[20];
    char name[80];
    float price;
} Book;

int main()
{
    Book book[1005];
    int index[1005];
    int m;

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &index[i]);
    }

    int n = 0;
    while (scanf("%s %s %f", book[n].num, book[n].name, &book[n].price) == 3)
    {
        n++;
    }
    Book bookback[n+1];
    for (int i = 0; i < n; i++)
    {
        bookback[i] = book[n-i-1];
    }
    

    for (int i = 0; i < m; i++)
    {
        int idx = index[i];
        printf("输出数组中下标为%d的图书信息\n", idx);
        printf("书号：%s\n", bookback[idx].num);
        printf("书名：%s\n", bookback[idx].name);
        printf("价格：%.2f\n", bookback[idx].price);
    }

    return 0;
}