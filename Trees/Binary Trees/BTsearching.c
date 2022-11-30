#include<stdio.h>
#include<stdlib.h>
#include "BTfunctions.c"
int search(Node* root, int ele)
{
    static int k=0;
    if(root)
    {
        if(root->data==ele)
        {
            k=1;
            return k;
        }
        if(!k)
            search(root->left,ele);
        if(!k)
            search(root->right,ele);
    }
}
void main()
{
     Node* tree=NULL;

    int root,ele;
    printf("Enter value of root node : ");
    scanf("%d",&root);

    tree=recursiveCreateBT(root);

    printf("\nLevel order is : ");
    levelorder(tree);

    printf("\nEnter element to be searched : ");
    scanf("%d",&ele);

    if(search(tree,ele))
        printf("Element found in tree");
    else
        printf("Element not found in tree");
}