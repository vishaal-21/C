#include<stdio.h>
#include<stdlib.h>
#include "BTfunctions.c"
//--------------------FUNCTION TO CALCULATE HEIGHT OF BT-----------------------//
int max(int a,int b)
{
    return a>b?a:b;
}
int height(Node* root)
{
    if(root==NULL)
        return 0;
    return (1+max(height(root->left),height(root->right)));
}
//-----------------------------------------------------------------------------//

//--------------------FUNCTION TO COUNT NODES IN  BT-------------------------//
int nodecount(Node* root)
{
    static int count=0;
    if(root)
    {
        nodecount(root->left);
        count++;
        nodecount(root->right);
    }
    return count;
}
//-----------------------------------------------------------------------------//

//--------------------FUNCTION TO COUNT LEAFS BT----------------------------//
int leafcount(Node* root)
{
    static int count=0;
    if(root)
    {
        leafcount(root->left);
        if(root->left==NULL && root->right==NULL)
            count++;
        leafcount(root->right);
    }
    return count;
}
//-----------------------------------------------------------------------------//

void main()
{
     Node* tree=NULL;

    int root;
    printf("Enter value of root node : ");
    scanf("%d",&root);

    tree=recursiveCreateBT(root);

    printf("\nLevel order is : ");
    levelorder(tree);

    printf("\nHeight of tree : %d",height(tree));
    printf("\nNumber of nodes : %d",nodecount(tree));
    printf("\nNumber of leafs : %d",leafcount(tree));
}