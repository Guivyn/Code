#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct Book
{
    char num[20];
    char name[80];
    float price;
    struct Book *next;
} Book;


int main()
{
    int m;
    scanf("%d", &m);

    int pos[1005];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &pos[i]);
    }

    Book *head = NULL;
    Book *tail = NULL;

    Book temp;

    while (scanf("%s %s %f",temp.num,temp.name,&temp.price)==3)
    {
        Book *node=malloc(sizeof(Book));
        if (node==NULL)
        {
            return 1;
        }

        strcpy(node->name, temp.name);
        strcpy(node->num, temp.num);
        node->price=temp.price;
        node->next = NULL;

        if (head==NULL)
        {
            head = tail = node;//三个指向一个
        }
        else
        {
            tail->next = node;//tail所指向的最后一个节点，现在指向node（新节点）
            tail = node ;//tail也指向node（新节点）
        }
    }

    Book *sorted = NULL;
    Book *cur = head;
    while (cur!=NULL)
    {
        Book *next = cur->next;
        if (sorted == NULL || sorted->price>cur->price)
        {
            cur->next = sorted;
            sorted = cur;
        }
        else
        {
            Book *p = sorted;
            while (p->next != NULL&&p->next->price <= cur->price)
            {
                p = p->next;
            }
            cur->next = p->next;
            p->next = cur;
        }
        cur = next;  
    }

    head = sorted;

    for (int i = 0; i < m; i++)
    {
        Book *q = head;
        for (int j = 0; j < pos[i] - 1; j++)
        {
            q = q->next;
        }
        printf("输出链表中第%d个位置的图书信息\n", pos[i]);
        printf("书号：%s\n", q->num);
        printf("书名：%s\n", q->name);
        printf("价格：%.2f\n", q->price);
    }

    Book *p = head;//再次设为head，开始free
    while (p!=NULL)
    {
        Book *tmp = p;
        p = p->next;
        free(tmp);
    }
}