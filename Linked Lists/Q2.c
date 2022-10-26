//INCOMPLETE!!! DO NOT WRITE

#include<stdio.h>
#include<stdlib.h>
#include "insert_functions.h"
void main()
{
    int n,i,k,item;

    printf("Enter size of list : ");
    scanf("%d",&n);

    struct node* list=NULL;

    printf("Enter list elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list=insertEnd(list,item);
    }

    printf("List is : ");
    display(list);

    printf("Enter number (<=%d) to rotate list : ",n);
    scanf("%d",&k);
}
