#include<stdio.h>
#include<math.h>
int conversion(long int);
void main()
{
    long int bin;

    printf("Enter binary number : ");
    scanf("%ld",&bin);

    printf("Binary %ld = Decimal %d",bin,conversion(bin));
}
int conversion(long int a)
{
    int dec=0,rem,i=0,flag=0;

    while(a>0)
    {
        rem=a%10;
        if(rem>1)
        {
            flag=1;
            break;
        }
        dec+=(rem*pow(2,i));
        a/=10;
        i++;
    }

    if(flag==0)
        return dec;
    else
        return -1;
}
