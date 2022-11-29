#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

// declaring a node
Node* getnode()
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    return ptr;
}

// inserting an element in the beginning
Node* insertFirst(Node *head, int item)
{
    Node *temp = head;
    Node *ptr = getnode();
    ptr->data = item;
    ptr->next = temp;
    head = ptr;
    return head;
}

// inserting an element in the end
Node* insertEnd(Node *head, int item)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = item;
    ptr->next = NULL;

    Node *p = head;

    while (p->next != NULL)
        p = p->next;

    p->next = ptr;
    return head;
}

// inserting an element at given index
Node* insertBetween(Node *head, int item, int index)
{
    Node* ptr=getnode();
    ptr->data=item;

    Node *temp=head;
    int i;
    for(i=0;i<index-1;i++)
        temp=temp->next;

    ptr->next=temp->next;
    temp->next=ptr;
    return head;
}

// deleting from the beginning
Node* deleteFront(Node *head)
{
    Node *temp = head;
    temp = temp->next;
    head = temp;
    return head;
}

// deleting from the end
Node* deleteEnd(Node *head)
{
    Node *ptr = (Node *)malloc(sizeof(Node));

    Node *p = head;

    while ((p->next)->next != NULL)
        p = p->next;

    p->next = NULL;
    return head;
}

// deleting from a given index
Node* deleteIndex(Node *head, int index)
{
    Node* temp1=head;
    Node* temp2;

    int i;
    for(i=0;i<index;i++)
    {
        temp2=temp1;
        temp1=temp1->next;
    }

    temp2->next=temp1->next;
    return head;
}

// display
void display(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
