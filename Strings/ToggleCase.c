#include<stdio.h>
#include<string.h>
void main()
{
    int count=0,i,len;
    char s[50];

    printf("Enter a sentence : ");
    gets(s);

    strcat(s," ");
    len=strlen(s);

    for(i=0;i<len;i++)
    {
        if(s[i]>=65 && s[i]<=90)
            s[i]+=32;
        else if(s[i]>=97 && s[i]<=122)
            s[i]-=32;
    }

    printf("New String is : %s",s);
}
