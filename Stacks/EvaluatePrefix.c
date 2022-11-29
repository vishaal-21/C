#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
typedef struct
{
	int arr[50];
	int top;
}Stack;
void push(Stack *s,int x,int n)
{
	s->arr[++s->top]=x;
}
int pop(Stack *s)
{
	return(s->arr[s->top--]);
}
int evaluate(char ch, int op1, int op2)
{
    switch(ch)
    {
    case '+':
        return (op1+op2);
        break;

    case '-':
        return (op1-op2);
        break;

    case '*':
        return (op1*op2);
        break;

    case '/':
        return (op1/op2);
        break;

    case '^':
        return pow(op1,op2);
        break;
    }
}
void main()
{
	Stack st;
	char prefix[50];
	st.top=-1;
	int i=0,k=0;
	printf("Enter numerical prefix expression : ");
	gets(prefix);

	int len=strlen(prefix);
    strrev(prefix);
    printf("%s\n",prefix);

    int op1,op2,result;

    while(prefix[i]!='\0')
    {
        int ch=prefix[i];
        if(isdigit(ch))
            push(&st,(ch-48),len);
        else
        {
            op1=pop(&st);
            op2=pop(&st);
            result=evaluate(ch,op1,op2);
            push(&st,result,len);
        }
        i++;
    }
    printf("Result = %d",pop(&st));
}