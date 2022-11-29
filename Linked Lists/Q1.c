//OUTPUT MIGHT BE WRONG

#include<stdio.h>
#include<stdlib.h>
#include "insert_functions.h"
struct node* merge(struct node* list1, struct node* list2)
{
    struct node* l1z=list1;

    struct node* p=list1;
    struct node* q=NULL;
    while(list2!=NULL)
    {
        while(p!=NULL)
        {
            if(p->data>=list2->data)
            {
                struct node* temp=list2;
                if(q==NULL)
                {
                    temp->next=p;
                    l1=temp;
                }
                else if(p->next==NULL)
                {
                    p->next=temp;
                    temp->next=NULL;
                }
                else
                {
                    q->next=temp;
                    temp->next=p;
                }
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        list2=list2->next;
    }

    return l1;
}
void main()
{
    int m,n,i,item;

    printf("Enter size of first list : ");
    scanf("%d",&m);

    printf("Enter size of second list : ");
    scanf("%d",&n);

    struct node* list1=NULL;
    struct node* list2=NULL;

    printf("Enter elements of first list in ascending order : \n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&item);
        list1=insertEnd(list1,item);
    }

    printf("Enter elements of second list in ascending order : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list2=insertEnd(list2,item);
    }

    printf("List 1 is : ");
    display(list1);

    printf("\nList 2 is : ");
    display(list2);

    printf("\nMerged list is : ");
    list1=merge(list1,list2);
    display(list1);
}
