#include<stdio.h>
#include<math.h>
int conversion(int);
void main()
{
    int n;

    printf("Enter decimal number : ");
    scanf("%d",&n);

    printf("Decimal %d = octal %d",n,conversion(n));
}
int conversion(int a)
{
    int rem,i=1;
    long int bin=0;

    while(a>0)
    {
        rem=a%8;
        a/=8;
        bin+=(rem*i);
        i*=10;
    }

    return bin;
}
