#include<stdio.h>
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
int isFull(Stack *s,int n)
{
	if (s->top == (n-1))
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
void display(Stack *s)
{
	int i;
	for(i=s->top;i>=0;i--)
		printf("%c\n",s->arr[i]);
}
void main()
{
	Stack st;
	st.top=-1;
	int n;
	printf("Enter max size of stack : ");
	scanf("%d",&n);

	int choice=0;

	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Display\n");
	printf("-1 to stop\n");

	while(choice!=-1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		if(choice==1)
		{
			char ch;
			if(isFull(&st,n)==1)
				printf("Stack Overflow");
			else
			{
				printf("Enter a character : ");
				scanf(" %c",&ch);
				push(&st,ch,n);
			}
		}
		else if(choice==2)
		{
			if(isEmpty(&st) == 1)
				printf("Stack Underflow");
			else
				pop(&st);
		}
		else if(choice==3)
			display(&st);
	}
}
