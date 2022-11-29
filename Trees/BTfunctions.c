#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;

//QUEUE FUNCTIONS CREATION------------------------------------------------//
typedef struct 
{
    Node* arr[50];
    int front, rear;
}Queue;

int isEmpty(Queue *q)
{
    if(q->front==q->rear)
        return 1;
    return 0;
}

Node* dequeue(Queue *q)
{
    return q->arr[++q->front];
}

void enqueue(Queue *q, Node* temp)
{
    q->arr[++q->rear]=temp;
}
//-------------------------------------------------------------------------//
//NODE CREATION
Node* getnode()
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}
//-----------------------------TRAVERSALS------------------------------------//
//INORDER
void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

//PREORDER
void preorder(Node* root)
{
    if(root)
    {
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//POSTORDER
void postorder(Node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
}

//LEVEL ORDER
void levelorder(Node* root)
{
    Queue q;
    q.front=-1;
    q.rear=-1;
    if(root==NULL)
    {
        printf("Empty tree");
        return;
    }

    enqueue(&q,root);
    while(!isEmpty(&q))
    {
        Node* temp=dequeue(&q);
        printf("%d  ",temp->data);
        if(temp->left)
            enqueue(&q,temp->left);

        if(temp->right)
            enqueue(&q,temp->right);
    }
}
//------------------------------------------------------------------------------//
//CREATING BT UISNG RECURSION
Node* recursiveCreateBT(int item)
{
    int x;
    if(item!=-1)
    {
        Node* temp=getnode();
        temp->data=item;

        printf("Enter left child of %d : ",item);
        scanf("%d",&x);
        temp->left=recursiveCreateBT(x);

        printf("Enter right child of %d : ",item);
        scanf("%d",&x);
        temp->right=recursiveCreateBT(x);

        return temp;
    }
    else
        return NULL;
}
//-----------------------------------------------------------------------------//

void main()
{
    Node* tree=NULL;

    int root;
    printf("Enter value of root node : ");
    scanf("%d",&root);

    tree=recursiveCreateBT(root);

    printf("Inorder is : ");
    inorder(tree);

    printf("\nPreoder is : ");
    preorder(tree);

    printf("\nPostorder is : ");
    postorder(tree);

    printf("\nLevel order is : ");
    levelorder(tree);
}
/*
                        2
                       / \
                      3   4
                     / \   \
                    8   9   7
*/