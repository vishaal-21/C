#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int arr[10];
    int top,size;
} Stack;
int isEmpty(Stack* s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void push(Stack *s,int x)
{
    s->arr[++s->top] = x;
}
int pop(Stack *s)
{
    return s->arr[s->top--];
}
void display(Stack* s)
{
    int i;
    printf("Queue is : \n");
    for(i=0;i<=s->top;i++)
        printf("%d\n",s->arr[i]);
}
int main()
{
    Stack s1;
    Stack s2;
    s1.top = -1;
    s2.top = -1;

    int choice,n,item;
    printf("Enter max queue size : ");
    scanf("%d",&n);

    s1.size=n;
    s2.size=n;
    printf("\n1.Enqueue\t2.Dequeue\t3.Display\t0.Exit\n");
    do
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter number : ");
            scanf("%d",&item);
            push(&s1,item);
        }
        else if (choice == 2)
        {
            if (s2.top == -1)
            {
                while (s1.top != -1)
                    push(&s2,pop(&s1));
            }
        }
        else if(choice==3)
        {
            if(isEmpty(&s1))
                display(&s2);
            if(isEmpty(&s2))
                display(&s1);
        }
    }while (choice != 0);
}
