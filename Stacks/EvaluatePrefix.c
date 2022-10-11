#include<stdio.h>
#include<string.h>
#include<math.h>
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
int isDigit(char ch)
{
    if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9')
    {
        //printf("1");
        return 1;
    }

    else
    {
        //printf("0");
        return 0;
    }
}
char evaluate(char ch, int op1, int op2)
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
	char prefix[50]="-/*2*5+3652",ch;
	st.top=-1;
	int i=0,k=0;
	//printf("Enter numerical prefix expression : ");
	//gets(prefix);

	int len=strlen(prefix);
    strrev(prefix);
    printf("%s\n",prefix);

    char op1,op2,result;

    while(prefix[i]!='\0')
    {
        ch=prefix[i];
        if(isDigit(ch)==1)
            push(&st,ch,len);
        else
        {
            op1=pop(&st);
            op2=pop(&st);
            result=evaluate(ch,op1,op2);
            push(&st,result,len);
            printf("%c\t%c\t%c\n",op1,op2,result);
        }
        i++;
    }
    printf("Result = %d",pop(&st));
}
