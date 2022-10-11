#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void palin(char str[],char s[],int i,int j)
{
    if(str[i]=='\0')
		return;
	 s[i]+=str[j];

	 palin(str,s,++i,--j);
}
void main()
{
	char str[100];
	char s[100]="";
	printf("Enter a sentence : ");
	gets(str);

	int i=0;
	int j=(strlen(str))-1;

	palin(str,s,i,j);
	printf("Palindrome string : %s\n",s);

	if(strcmp(str,s)!=0)
		printf("Not Palindrome\n");
	else
		printf("Palindrome\n");
}
