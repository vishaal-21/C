#include<stdio.h>
#include<stdlib.h>
#include "BTfunctions.c"
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