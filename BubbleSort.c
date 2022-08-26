#include<stdio.h>
void main()
{
    int a[50],n,i,j,temp;
    char ch;

    printf("Enter array size : ");
    scanf("%d",&n);

    printf("Enter %d numbers : \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Array before sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nSort Ascending(a/A) or Descending(d/D) : ");
    getchar();
    scanf("%c",&ch);

    switch(ch)
    {
        case 'a':case 'A':
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        break;

        case 'd':case'D':
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]<a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        break;

        default:
        printf("INVALID!\n");

    }

    printf("Array after sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}



