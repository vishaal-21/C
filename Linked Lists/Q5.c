#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "insert_functions.h"
void main()
{
    int n,i,item;

    struct node* list;

    int choice;
    printf("1. Create a new linked list and display\n");
    printf("2. Delete elements equal to square of entered element\n");
    printf("3. Display list\n");
    printf("0. STOP\n");

    do
    {
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter size of list : ");
            scanf("%d",&n);

            list = (struct node*)calloc(n,sizeof(struct node));
            list=NULL;

            printf("Enter list elements : ");
            for(i=0;i<n;i++)
            {
                scanf("%d",&item);
                list=insertEnd(list,item);
            }

            printf("\nList before deletion : ");
            display(list);
            printf("\n");
        }
        else if(choice==2)
        {
            struct node* ptr = list;
            struct node* q = list;
            struct node* p=(struct node*)malloc(sizeof(struct node));

            printf("Enter key element : ");
            scanf("%d",&item);
            item*=item;

            for(i=0;i<n;i++)
            {
                if(q->data==item)
                {
                    if(q==ptr)
                    {
                        ptr=q->next;
                        q=ptr;
                    }
                    else if(q->next==NULL)
                    {
                        p->next=NULL;
                        break;
                    }
                    else
                    {
                        p->next=q->next;
                        q=q->next;
                    }
                }
                else
                {
                    p=q;
                    q=q->next;
                }
            }
        }
        else if(choice==3)
        {
            printf("New list is : ");
            display(list);
        }
    }while(choice!=0);
}
