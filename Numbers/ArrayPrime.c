#include<stdio.h>
void main()
{
    int a[50],n;

    printf("Enter array size : ");
    scanf("%d",&n);

    printf("Enter %d numbers : \n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Array is : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nPrime Numbers are : ");
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=1;j<=a[i];j++)
        {
            if(a[i]%j==0)
                count++;
        }
        if(count==2)
            printf("%d ",a[i]);
    }
}

