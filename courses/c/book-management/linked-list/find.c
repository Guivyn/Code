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
    int type,pos;
    char findName[80];

    scanf("%d", &type);
    if (type == 1)
    {
        scanf("%d", &pos);
    }
    else
    {
        scanf("%s", findName);
    }

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
    
    if (type==1)
    {
        Book *choice = head;
        for (int i = 0; i < pos-1; i++)
        {
            choice = choice->next;
        }
        printf("%s %s %.2f\n", choice->num, choice->name, choice->price);
    }
    else
    {
        int found = 0;
        Book *choice = head;
        while (choice != NULL)
        {
            if (strcmp(choice->name, findName) == 0)
            {
                printf("%s %s %.2f\n", choice->num, choice->name, choice->price);
                found = 1;
            }
            choice = choice->next;
        }

        if (!found)
        {
            printf("未找到\n");
        }

    }

    Book *p = head;
    while (p!=NULL)
    {
        Book *tmp = p;
        p = p->next;
        free(tmp);
    }
}