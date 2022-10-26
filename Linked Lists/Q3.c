#include<stdio.h>
#include<stdlib.h>
#include "insert_functions.h"
void main()
{
    int n,i,item;

    printf("Enter number of fibonacci numbers : ");
    scanf("%d",&n);

    struct node* list = (struct node*)calloc(n,sizeof(struct node));
    struct node* first = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));

    first=list;
    list->data=0;
    list->next=second;

    second->data=1;
    second->next=NULL;

    for(i=2;i<n;i++)
    {
        item = (first->data) + (second->data);
        list=insertEnd(list,item);

        first=first->next;
        second=second->next;
    }

    printf("Fibonacci Sequence is : ");
    display(list);
}
