//OUTPUT MIGHT BE WRONG

#include<stdio.h>
#include<stdlib.h>
#include "insert_functions.h"
struct node* merge(struct node* list1, struct node* list2)
{
    struct node* ptr1=list1;
    struct node* ptr2=list2;

    struct node* ptr = list1;
    struct node* q=list1;
    struct node* p;


    while(list2!=NULL)
    {
        q=ptr1;
        p=NULL;
        while(q!=NULL)
        {
            if(q->data>=list2->data)
            {
                struct node* temp=list2;
                if(q==ptr1)
                {
                    temp->next=q;
                    ptr1=temp;
                }
                else if(q->next==NULL)
                {
                    p->next=temp;
                    temp->next=NULL;
                }
                else
                {
                    temp->next=q;
                    p->next=temp;
                    p=p->next;
                }
                break;
            }
            else
            {
                p=q;
                q=q->next;
            }
        }
        list2=list2->next;
    }

    return list1;
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
