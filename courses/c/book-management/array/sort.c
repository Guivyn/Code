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

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (book[j].price > book[j + 1].price)
            {
                Book tmp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int idx = index[i];
        printf("输出数组中下标为%d的图书信息\n", idx);
        printf("书号：%s\n", book[idx].num);
        printf("书名：%s\n", book[idx].name);
        printf("价格：%.2f\n", book[idx].price);
    }

    return 0;
}