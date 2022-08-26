#include<stdio.h>
void main()
{
    int a[50][50],t[50][50],m,n,count=0,i,j;

    printf("Enter number of rows and columns : \n");
    scanf("%d%d",&m,&n);

    if(m==n)
    {
        printf("Enter %d elements : \n",(m*n));
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);

        printf("Matrix is : \n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }

       for(i=0;i<m;i++)
        for(j=0;j<n;j++)
                if(a[i][j]==a[j][i])
                    count++;
    }

    if(count==(m*n))
        printf("Symmetric");
    else
        printf("NOT Symmetric");
}
