#include<stdio.h>
#include<stdlib.h>
#include "BSTfunctions.c"
Node* inorderPredecessor(Node* root)
{
    root=root->left;
    while(root->right!=NULL)
        root=root->right;

    return root;
}
Node* deleteNode(Node* root, int ele)
{
    Node* temp;
    if(root==NULL)
    {
        return NULL;
    }

    if(root->left==NULL && root->right==NULL)
        free(root);

    if(ele<root->data)
        deleteNode(root->left,ele);
    else if(ele>root->data)
        deleteNode(root->right,ele);
    else
    {
        temp=inorderPredecessor(root);
        root->data=temp->data;
        deleteNode(root->left,temp->data);
    }

    return root;
}