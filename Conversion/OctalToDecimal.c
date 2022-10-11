#include<stdio.h>
#include<math.h>
int conversion(int);
void main()
{
    int oct;

    printf("Enter octal number : ");
    scanf("%d",&oct);

    printf("Octal %d = Decimal %d",oct,conversion(oct));
}
int conversion(int a)
{
    int dec=0,rem,i=0,flag=0;

    while(a>0)
    {
        rem=a%10;
        if(rem>7)
        {
            flag=1;
            break;
        }
        dec+=(rem*pow(8,i));
        a/=10;
        i++;
    }

    if(flag==0)
        return dec;
    else
        return -1;
}
