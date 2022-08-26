#include<stdio.h>
void main()
{
    int a[50],n,largest,smallest;

    printf("Enter array size : ");
    scanf("%d",&n);

    printf("Enter %d numbers : ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    largest=smallest=a[0];

    for(int i=0;i<n;i++)
    {
        if(a[i]>largest)
            largest=a[i];
        else if(a[i]<smallest)
            smallest=a[i];
    }

    printf("Array is : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\n");
    printf("Largest = %d\n",largest);
    printf("Smallest = %d",smallest);
}
