#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[50];
    int count;
    struct node* next;
};
struct node* create(struct node* head,char name[])
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    strcpy(ptr->data,name);
    ptr->next=NULL;

    struct node* p = head;

    if(p==NULL)
        return ptr;
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }

        p->next=ptr;
    }
    return head;
}
void search(struct node* head)
{
    struct node* p = head;
    struct node* q = head->next;

    while(p!=NULL)
    {
        while(q!=NULL)
        {
            if(strcmpi(p->data,q->data))
            {

            }
        }

        p=p->next;
    }
}
void display(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%s ",ptr->data);
        ptr = ptr->next;
    }
}
void main()
{
    char name[50];
    int i,n;

    printf("Enter number of names : ");
    scanf("%d",&n);

    struct node* list=NULL;

    printf("Enter the names : ");
    for(i=0;i<n;i++)
    {
        scanf("%s",&name);
        list=create(list,name);
    }

    printf("List is : ");
    display(list);

    search(list);
}
