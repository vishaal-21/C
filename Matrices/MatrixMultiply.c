#include<stdio.h>
void main()
{
    int m1,n1,m2,n2,i,j,k;

	printf("Enter array dimension of matrix 1 : \n");
    scanf("%d%d",&m1,&n1);

    printf("Enter array dimension of matrix 2 : \n");
	scanf("%d%d",&m2,&n2);

    if(m2==n1)
	{
        int a[m1][n1];
		int b[m2][n2];

		printf("Enter %d matrix 1 elements : ",(m1*n1));
		for(i=0;i<m1;i++)
			for(j=0;j<n1;j++)
				scanf("%d",&a[i][j]);

		printf("Enter %d matrix 1 elements : ",(m2*n2));
		for(i=0;i<m2;i++)
			for(j=0;j<n2;j++)
				scanf("%d",&b[i][j]);

		printf("Matrix 1 : \n");
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n1;j++)
            {
              printf("%d ",a[i][j]);
            }
            printf("\n");
		}

		printf("Matrix 2 : \n");
		for(i=0;i<m2;i++)
		{
			for(j=0;j<n2;j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
		}

		int mul[m1][n2];

		for(i=0;i<m1;i++)
		{
			for(j=0;j<n2;j++)
			{
			    mul[i][j]=0;
			    for(k=0;k<n1;k++)
                {
                    mul[i][j]+=(a[i][k]*b[k][j]);
                }
			}
		}

		printf("Product matrix : \n");
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n2;j++)
            {
                printf("%d ",mul[i][j]);
            }
            printf("\n");
		}
	}
	else
		printf("Matrix multiplication not possible");
}
