#include <stdio.h>
typedef struct
{
    int arr[50];
    int front1,front2,rear1,rear2,size,size1,size2;
}Queue;

void insertcq(Queue* q, int n)
{
    int item;

    switch(n)
    {
    case 1:
        if((q->front1==0 && q->rear1==q->size1-1) || (q->front1==q->rear1+1))
            printf("Queue 1 is full");
        else
        {
            if(q->front1==-1)
                q->front1=0;

            printf("Enter number : ");
            scanf("%d",&item);

            q->rear1=(q->rear1+1)%q->size1;
            q->arr[q->rear1]=item;
        }
        break;

    case 2:
        if((q->front2==q->size1 && q->rear2==q->size-1) || (q->front2==q->rear2+1))
            printf("Queue 2 is full");
        else
        {
            if(q->front2==q->size-1)
                q->front2=q->size;

            printf("Enter number : ");
            scanf("%d",&item);

            q->rear2=(q->rear2+1)%q->size2;
            q->arr[q->rear2]=item;
        }
        break;
    }
}
void deletecq(Queue* q, int n)
{
    switch(n)
    {
    case 1:
        if(q->front1==-1)
            printf("Queue 1 is empty");
        else
        {
            if(q->front1==q->rear1)
            {
                q->front1=-1;
                q->rear1=-1;
            }
            else
                q->front1=(q->front1+1)%q->size1;
        }
        break;

    case 2:
        if(q->front2==q->size1-1)
            printf("Queue 2 is empty");
        else
        {
            if(q->front2==q->rear2)
            {
                q->front2=q->size1-1;
                q->rear2=q->size1-1;
            }
            else
                q->front2=(q->front2+1)%q->size2;
        }
        break;
    }
}
void displaycq(Queue* q)
{
    int i;

    if(q->front1==-1)
            printf("Queue 1 is empty\n");
    else
    {
        printf("\nQueue 1 is:\n");
        for(i=q->front1; i!=q->rear1; i=(i+1)%q->size1)
            printf("%d\n",q->arr[i]);

        printf("%d\n",q->arr[i]);
    }

    if(q->front2==q->size1-1)
        printf("Queue 2 is empty");
    else
    {
        printf("\nQueue 2 is:\n");
        for(i=q->front2; i!=q->rear2; i=(i+1)%q->size2)
            printf("%d\n",q->arr[i]);

        printf("%d\n",q->arr[i]);
    }
}

void main()
{
    int n,choice;
    printf("Enter max size : ");
    scanf("%d",&n);

    Queue q;
    q.size=n;

    q.front1=-1;
    q.rear1=-1;
    q.size1=(q.size/2)+1;

    q.front2=q.size1-1;
    q.rear2=q.size-1;
    q.size2=q.size-q.size1;

    printf("1. Enqueue Queue 1\t2.Enqueue Queue 2\t3.Dequeue Queue 1\t4.Dequeue Queue 2\t5.Display\t0.Stop");

    do
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        if(choice==1 || choice==2)
        {
            insertcq(&q,choice);
        }
        else if(choice==3 || choice==4)
        {
            deletecq(&q,choice-2);
        }
        else if(choice==5)
            displaycq(&q);
    }while(choice!=0);
}
