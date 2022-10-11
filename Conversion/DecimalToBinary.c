#include<stdio.h>
#include<math.h>
long int conversion(int);
void main()
{
    int n;

    printf("Enter decimal number : ");
    scanf("%d",&n);

    printf("Decimal %d = Binary %ld",n,conversion(n));
}
long int conversion(int a)
{
    int rem,i=1;
    long int bin=0;

    while(a>0)
    {
        rem=a%2;
        a/=2;
        bin+=(rem*i);
        i*=10;
    }

    return bin;
}
