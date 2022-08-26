#include<stdio.h>
#include<math.h>
void main()
{
    int a[50][50],b[50][50],m,n,i,j,temp;

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
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                {
                    temp=a[i][j];
                    a[i][j]=a[i][m-1-j];
                    a[i][m-1-j]=temp;
                }
            }
        }

        printf("Array after switching : \n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("IVNVALID MATRIX");

}
