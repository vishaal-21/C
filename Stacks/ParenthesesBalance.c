#include<stdio.h>
#include<string.h>
typedef struct
{
	char arr[50];
	int top;
}Stack;
int isEmpty(Stack *s)
{
	if (s->top==-1)
		return 1;
	else
		return 0;
}
void push(Stack *s,char x,int n)
{
	s->arr[++s->top]=x;
}
char pop(Stack *s)
{
	return(s->arr[s->top--]);
}
void main()
{
	Stack st;
	char expression[50],ch;
	st.top=-1;
	int i=0,k=0;
	printf("Enter expression : ");
	gets(expression);

	int len=strlen(expression);
    printf("%s\n",expression);

    int flag1=1,flag2=1,flag3=1;

	while(expression[i]!='\0')
    {
        ch=expression[i];
        if(ch=='(' || ch=='[' || ch=='{')
            push(&st,ch,len);
        else if(ch==')' || ch==']' || ch=='}')
        {
            if(ch==')')
            {
                if(st.arr[st.top]=='(')
                    pop(&st);
                else
                {
                    flag1=0;
                    break;
                }
            }
            else if(ch==']')
            {
                if(st.arr[st.top]=='[')
                    pop(&st);
                else
                {
                   flag2=0;
                   break;
                }
            }
            else if(ch=='}')
            {
                if(st.arr[st.top]=='{')
                    pop(&st);
                else
                {
                    flag3=0;
                    break;
                }
            }
        }
        i++;
    }

    if(isEmpty(&st)==0 || flag1==0 || flag2==0 || flag3==0)
        printf("Unbalanced");
    else
        printf("Balanced");
}
