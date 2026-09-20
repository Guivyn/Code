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
    Book *head = NULL;
    Book *tail = NULL;

    Book temp;

    int num;

    scanf("%d", &num);

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
    
    //删除
    if (num == 1)
    {
        /* 删除头节点 */
        Book *del = head;
        head = head->next;
        free(del);
    }
    else
    {
    Book *delete;
    Book *prev=head;

    for (int i = 1; i < num-1; i++)
    {
        prev=prev->next;
    }

    delete = prev->next;
    prev->next = delete->next;
    free(delete);
    }
    
    printf("书号 书名 价格\n");

    Book *p = head;//p设为head，开始打印
    while (p!=NULL)
    {
        printf("%s %s %.2f\n", p->num, p->name, p->price);
        p = p->next;
    }//循环结束之后指向NULL

    p = head;//再次设为head，开始free
    while (p!=NULL)
    {
        Book *tmp = p;
        p = p->next;
        free(tmp);
    }
}