#include<stdio.h>
#include<stdlib.h>
#include "BTfunctions.c"
//------------------------INSERTION-----------------------------------//
void insert(Node* root, char order[], int ele)
{
    Node* temp=getnode();
    Node* currNode, *parent;
    temp->data=ele;
    temp->left=NULL; 
    temp->right=NULL;

    int i=0;
    parent=NULL;
    currNode=root;
    while(currNode && order[i])
    {
        parent=currNode;
        if(order[i]=='L' || order[i]=='l')
            currNode=currNode->left;
        if(order[i]=='R' || order[i]=='r')
            currNode=currNode->left;
        i++;
    }
    if(currNode!=NULL || order[i]!='\0')
    {
        printf("No insertion possible");
        free(temp);
        return;
    }

    if(order[i-1]=='L' || order[i-1]=='l')
            parent->left=temp;
    if(order[i-1]=='R' || order[i-1]=='r')
            parent->right=temp;
}
void main()
{
    Node* tree=NULL;

    int root,ele;
    char order[50];
    printf("Enter value of root node : ");
    scanf("%d",&root);

    tree=recursiveCreateBT(root);

    printf("\nLevel order is : ");
    levelorder(tree);

    printf("\nEnter element to be added : ");
    scanf("%d",&ele);
    printf("Enter addition sequence : ");
    scanf("%s",order);
    insert(tree,order,ele);
    printf("\nLevel order after insertion is : ");
    levelorder(tree);
}
/*
                        2
                       / \
                      3   4
                     / \   \
                    8   9   7
*/