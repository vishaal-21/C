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

    printf("Enter size of list : ");
    scanf("%d",&n);

    struct node* list = (struct node*)calloc(n,sizeof(struct node));
    list=NULL;

    printf("Enter list elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list=insert(list,item);
    }

    printf("List is : ");
    display(list);

    struct node* odd = NULL;
    struct node* even = NULL;

    for(i=0;i<n;i++)
    {
        item=list->data;
        if(i%2==0)
        {
            even=insert(even,item);
        }
        else
        {
            odd=insert(odd,item);
        }
        list=list->next;
    }

    printf("\nOdd index list is : ");
    display(odd);
    printf("\nEven index list is : ");
    display(even);
}
