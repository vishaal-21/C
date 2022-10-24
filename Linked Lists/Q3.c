#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node* head, int item)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    ptr->next=NULL;

    struct node* p = head;

    while(p->next!=NULL)
    {
        p=p->next;
    }

    p->next=ptr;
    return head;
}

void display(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

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
        list=insert(list,item);

        first=first->next;
        second=second->next;
    }

    printf("Fibonacci Sequence is : ");
    display(list);
}
