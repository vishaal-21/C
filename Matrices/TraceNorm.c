#include<stdio.h>
#include<math.h>
void main()
{
    int a[50][50],m,n,i,j,trace=0,norm=0,sos=0;

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
                    trace+=a[i][j];

                sos+=(a[i][j]*a[i][j]);
            }
        }
    }

    norm=sqrt(sos);
    printf("Trace = %d\n",trace);
    printf("Norm = %d",norm);
}


