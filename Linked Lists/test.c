#include<stdio.h>
#include<stdlib.h>
#include "insert_functions.h"

void rotate(struct node** head, int k)
{
    struct node* current = *head;
    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;

    struct node* knode = current;
    while (current->next != NULL)
        current = current->next;
    current->next = *head;
    *head = knode->next;
    knode->next = NULL;
}
void main()
{
    int n,i,k,item;

    printf("Enter size : ");
    scanf("%d",&n);

    struct node* list=NULL;
    struct node* list2=NULL;

    printf("Enter elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list=insertEnd(list,item);
        list2=insertEnd(list2,item);
    }
    printf("\nNmber of times to rotate <=%d : ",n);
    scanf("%d",&k);
    rotate(&list, n-k);
    printf("Right Rotate: \n");
    display(list);
    printf("\n");
    rotate(&list2, k);
    printf("\nLeft Rotate: \n");
    display(list2);
    printf("\n");

}
