#include<stdio.h>
void main()
{
    int a[50],n,i,j,ele,pos=-1,low,high,mid;

    printf("Enter array size : ");
    scanf("%d",&n);

    printf("Enter %d numbers : \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Numbers are : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nEnter element to be searched : ");
    scanf("%d",&ele);

    low=a[0],high=a[n-1];

    while(low<=high)
    {
        mid=(low+high)/2;

        if(ele>a[mid])
            low=mid+1;
        else if(ele<a[mid])
            high=mid-1;
        else if(ele==a[mid])
        {
            pos=mid;
            break;
        }
    }

    if(pos!=-1)
        printf("Element found at position %d",pos);
    else
        printf("Element not found");
}
