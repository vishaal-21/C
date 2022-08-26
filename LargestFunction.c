#include<stdio.h>
void Largest(int[]);
int n;
void main()
{
    int a[50],i;

    printf("Enter number of terms : ");
    scanf("%d",&n);

    printf("Enter %d numbers : ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Numbers are : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    Largest(a);
}
void Largest(int b[])
{
    int i,l=b[0];

    for(i=0;i<n;i++)
    {
        if(b[i]>l)
            l=b[i];
    }

    printf("\nLargest = %d",l);
}
