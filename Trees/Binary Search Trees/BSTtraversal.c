#include<stdio.h>
#include<stdlib.h>
#include "BSTfunctions.c"
void main()
{
    Node* tree=NULL;

    int root;
    printf("Enter value of root node : ");
    scanf("%d",&root);

    tree=recursiveCreateBST(root);

    printf("Inorder is : ");
    inorder(tree);

    printf("\nPreoder is : ");
    preorder(tree);

    printf("\nPostorder is : ");
    postorder(tree);

    printf("\nLevel order is : ");
    levelorder(tree);
}