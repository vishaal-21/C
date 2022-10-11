#include<stdio.h>
int Fact(int);
void main()
{
    int n,r,ncr;

    printf("Enter values of n and r in nCr : ");
    scanf("%d%d",&n,&r);

    ncr=Fact(n)/(Fact(r)*Fact(n-r));

    printf("Value of %dC%d is = %d",n,r,ncr);
}
int Fact(int a)
{
   if(a==0 || a==1)
    return 1;
   else
    return a*Fact(a-1);
}
