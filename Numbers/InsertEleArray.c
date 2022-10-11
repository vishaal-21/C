#include<stdio.h>
void main()
{
    int a[50],n,pos,ele,i;

    printf("Enter array size : ");
    scanf("%d",&n);

    printf("Enter %d numbers : \n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Array is : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nEnter element to be added : \n");
    scanf("%d",&ele);
    printf("Enter position of element : \n");
    scanf("%d",&pos);

    if(pos>=0 && pos<n)
    {
       for(i=n;i>=pos;i--)
       {
           a[i+1]=a[i];
       }
       a[pos]=ele;
       n++;
    }
    else
        printf("Enter valid position!");

    printf("Array after addition is : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
