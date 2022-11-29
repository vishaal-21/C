#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *right;
    struct node *left;   
} Node;

// declaring a node
Node* getnode()
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    return ptr;
}

// inserting an element in the beginning
void insertFirst(Node **head, int item)
{
    Node *temp = *head;
    
    Node *ptr = getnode();
    ptr->left=NULL;
    ptr->data = item;
    ptr->right = temp;

    *head = ptr;
}

// inserting an element in the end
void insertEnd(Node **head, int item)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = item;
    ptr->right = NULL;

    Node *p = *head;

    while (p->right != NULL)
        p = p->right;

    p->right = ptr;
    ptr->left=p;
}

// inserting an element at given index
void insertBetween(Node **head, int item, int index)
{
    Node* ptr=getnode();
    ptr->data=item;

    Node *temp=*head;
    int i;
    for(i=0;i<index-1;i++)
        temp=temp->right;

    ptr->right=temp->right;
    ptr->left=temp;
    temp->right=ptr;
}

// deleting from the beginning
void deleteFront(Node **head)
{
    Node *temp = *head;
    temp = temp->right;
    *head = temp;
}

// deleting from the end
void deleteEnd(Node **head)
{
    Node *ptr = (Node *)malloc(sizeof(Node));

    Node *p = *head;

    while ((p->right)->right != NULL)
        p = p->right;

    p->right = NULL;
}

// deleting from a given index
void deleteIndex(Node **head, int index)
{
    Node* temp1=*head;
    Node* temp2;

    int i;
    for(i=0;i<index;i++)
    {
        temp2=temp1;
        temp1=temp1->right;
    }

    (temp1->right)->left=temp2;
    temp2->right=temp1->right;
}

// display
void display(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}