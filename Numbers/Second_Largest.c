#include<stdio.h>
int i,n;
int large(int arr[])
{
    int largest=arr[0],slargest=arr[0];

    for(i=0;i<n;i++)
    {
        if(arr[i]>largest && arr[i]>slargest)
        {
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest)
            slargest=arr[i];
    }

    return slargest;
}
void main()
{
    printf("Enter array size : ");
    scanf("%d",&n);

    int a[n];

    printf("Enter %d numbers : ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Second largest number = %d", large(a));
}
