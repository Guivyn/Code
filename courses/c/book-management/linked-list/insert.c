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
    Book insert;
    Book temp;
    int pos;

    scanf("%d", &pos);        // 第 1 行：位置
    scanf("%s", insert.num);  // 第 2 行：书号
    scanf("%s", insert.name); // 第 3 行：书名
    scanf("%f", &insert.price); // 第 4 行：价格

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


    Book *newNode = (Book *)malloc(sizeof(Book));
    if (newNode == NULL) return 1;
    strcpy(newNode->num, insert.num);
    strcpy(newNode->name, insert.name);
    newNode->price = insert.price;
    newNode->next = NULL;

    Book *index=head;
    for (int i = 0; i < pos-1; i++)
    {
        index = index->next;
    }

    newNode->next = index;

    if (pos==1)
    {
        head = newNode;      // 插到头部
        if (tail == NULL)
        {
            tail = newNode;
        }
    }
    else
    {
        Book *indexback = head;
        for (int i = 0; i < pos - 2 && indexback != NULL; i++)
        {
            indexback = indexback->next;
        }
        indexback->next = newNode;   // 前驱指新结点
        if (newNode->next == NULL) tail = newNode;
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