#include<stdio.h>
void splitPrime(int);
int isPrime(int);
void main()
{
    int n;

    printf("Enter a number : ");
    scanf("%d",&n);

    splitPrime(n);
}
void splitPrime(int a)
{
    int i,j,flag=0;
    for(i=2,j=a-2;i<=a/2;i++,j--)
    {
       if(isPrime(i)==1 && isPrime(a-i)==1)
       {
           printf("%d can be written as %d and %d\n",a,i,(a-i));
           flag=1;
       }
    }

    if(flag==0)
            printf("%d cannot be split into 2 primes",a);
}
int isPrime(int b)
{
    int count=0,i;

    for(i=1;i<=b;i++)
        if(b%i==0)
            count++;

    if(count==2)
        return 1;
    else
        return 0;
}
