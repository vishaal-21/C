#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int arr[50];
    int front, rear, size;
}Queue;
void enqueue(Queue* q)
{
    int item;

    if(q->rear==q->size-1)
        printf("Queue is full");
    else
    {
        if(q->front==-1)
            q->front=0;

        printf("Enter number : ");
        scanf("%d",&item);

        q->rear=q->rear+1;
        q->arr[q->rear]=item;
    }
}
void dequeue(Queue* q)
{
    if(q->front==-1)
        printf("Queue is empty");
    else
    {
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else
            q->front=q->front+1;
    }
}
void displayq(Queue* q)
{
    int i;

    printf("\nQueue is:\n");
    for(i=q->front; i!=q->rear; i=i+1)
        printf("%d\n",q->arr[i]);
    printf("%d\n",q->arr[i]);
}
void main()
{
    Queue q;
    q.front=-1;q.rear=-1;
    int choice,n;

    printf("Enter max queue size : ");
    scanf("%d",&n);
    q.size=n;

    printf("1. Enqueue\t2. Dequeue\t3. Display\t0. Stop");

    do
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        if(choice==1)
            enqueue(&q);
        else if(choice==2)
            dequeue(&q);
        else if(choice==3)
            displayq(&q);
    }while(choice!=0);
}
