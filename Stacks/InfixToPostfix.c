#include<stdio.h>
#include<string.h>
typedef struct
{
	char arr[50];
	int top;
}Stack;
void push(Stack *s,char x,int n)
{
	s->arr[++s->top]=x;
}
char pop(Stack *s)
{
	return(s->arr[s->top--]);
}
void peek(Stack *s)
{
	s->top--;
}
int precedence(char ele)
{
    switch(ele)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
void main()
{
	Stack st;
	char infix[50]="((a+(b*c))-d)",postfix[50],ch;
	st.top=-1;
	int i=0,k=0;
	printf("Enter infix expression : ");
	gets(infix);

	int len=strlen(infix);
	push(&st,'#',len);

	while(infix[i]!='\0')
    {
        ch=infix[i];
        switch(ch)
        {
        case '(':
            push(&st,ch,len);
            break;

        case ')':
            while(st.arr[st.top]!='(')
                postfix[k++]=pop(&st);
            peek(&st);
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(precedence(st.arr[st.top])>=precedence(ch))
            {
                postfix[k++]=pop(&st);
            }
            push(&st,ch,len);
            break;
        default:
            postfix[k++]=ch;
        }

        i++;
    }

    while(st.arr[st.top]!='#')
        postfix[k++]=pop(&st);
    postfix[k++]='\0';

    printf("Postfix expression is : \n%s",postfix);
}
