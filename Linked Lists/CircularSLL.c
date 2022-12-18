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
    Node *ptr = (Node*)malloc(sizeof(Node));
    return ptr;
}

// inserting an element in the beginning
Node* insertFirst(Node *head, int item)
{
    Node *temp = head;
    Node *ptr = getnode();
    ptr->data = item;

    if(head==NULL)
    {
        head=ptr;
        ptr->next=head;
    }
    else
    {
        while(temp->next!=head)
            temp=temp->next;

        temp->next=ptr;
        ptr->next = head;
        head = ptr;
    }
    return head;
}

// inserting an element in the end
Node* insertEnd(Node *head, int item)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = item;

    Node *p = head;

    while (p->next != NULL)
        p = p->next;

    p->next = ptr;
    ptr->next = head;
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
    Node *ptr = (Node *)malloc(sizeof(Node));

    Node *p = head;

    while (p->next != head)
        p = p->next;

    head=(p->next)->next;
    return head;
}

// deleting from the end
Node* deleteEnd(Node *head)
{
    Node *ptr = (Node *)malloc(sizeof(Node));

    Node *p = head;

    while ((p->next)->next != head)
        p = p->next;

    p->next = head;
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
void display(Node *head)
{
    Node *temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } while (temp!=head);
    printf("\n");
}

void main()
{
    Node* head=NULL;

    head=insertFirst(head,11);
    head=insertEnd(head,6);
    head=insertEnd(head,16);
    head=insertEnd(head,10);
    display(head);
}