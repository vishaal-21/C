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
        if(s[i]==' ')
            count++;
    }

    printf("Number of words = %d",count);
}
