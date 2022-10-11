#include<stdio.h>
#include<string.h>
void main()
{
    int count=0,i,len;
    char s[50],word[50];

    printf("Enter a sentence : ");
    gets(s);

    strcat(s," ");
    len=strlen(s);

    printf("Enter word to be deleted : ");
    gets(word);

    printf("New string : ");
    for(i=0;i<len;i++)
    {
        int j=0;
        char temp[50]="";
        while(s[i]!=' ')
        {
            temp[j]=s[i];
            i++;
            j++;
        }

        if((strcmpi(word,temp))!=0)
            printf("%s ",temp);
    }
}
