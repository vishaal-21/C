#include<stdio.h>
void isPalin(int);
void main()
{
    int n;

    printf("Enter a number : ");
    scanf("%d",&n);

    isPalin(n);
}
void isPalin(int a)
{
    int rev=0,rem,num=a;

    while(a>0)
    {
        rem=a%10;
        rev=(10*rev)+rem;
        a/=10;
    }

    if(num==rev)
        printf("Palindrome");
    else
        printf("Not Palindrome");
}
