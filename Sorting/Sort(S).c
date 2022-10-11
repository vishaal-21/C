#include<stdio.h>
void main()
{
    int a[50],n,i,j,temp,position;
    char ch;

    printf("Enter array size : ");
    scanf("%d",&n);

    printf("Enter %d numbers : \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Array before sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    for(i=0;i<n-1;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[position])
                position=j;
        }

        if(position!=i)
        {
            temp=a[position];
            a[position]=a[i];
            a[i]=temp;
        }

    }

    printf("\nArray after ascending sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    for(i=0;i<n-1;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]>a[position])
                position=j;
        }

        if(position!=i)
        {
            temp=a[position];
            a[position]=a[i];
            a[i]=temp;
        }

    }

    printf("\nArray after descending sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
