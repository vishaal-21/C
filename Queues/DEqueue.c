#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int arr[50];
    int front, rear, size;
}Queue;

int isEmpty(Queue *q)
{
    if(q->front==q->rear)
        return 1;
    else
    {
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        return 0;
    }
}

int isFull(Queue *q)
{
    if(q->front==(q->rear+1)%q->size)
        return 1;
    else
    {
        if(q->front==-1)
            q->front=0;
        return 0;
    }
}

void insertFront(Queue *q)
{
    int item;
    if(isFull(q))
        printf("Queue is full");
    else
    {
        printf("Enter number : ");
        scanf("%d",&item);

        if(q->front==0)
            q->front=q->size-1;
        else
            q->front=q->front-1;

        q->arr[q->front]=item;
    }
}

void insertEnd(Queue* q)
{
    int item;
    if(isFull(q))
        printf("Queue is full");
    else
    {
        printf("Enter number : ");
        scanf("%d",&item);

        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear]=item;
    }
}

void deleteFront(Queue* q)
{
    if(isEmpty(q))
        printf("Queue is empty");
    else
        q->front=(q->front+1)%q->size;
}

void deleteEnd(Queue *q)
{
    if(isEmpty(q))
        printf("Queue is empty");
    else
    {
        if(q->rear==0)
            q->rear=q->size-1;
        else
            q->rear=q->rear-1;
    }
}

void display(Queue* q)
{
    int i;

    printf("\nQueue is:\n");
    for(i=q->front; i!=q->rear; i=(i+1)%q->size)
        printf("%d ",q->arr[i]);
    printf("%d ",q->arr[i]);
}

void main()
{
    Queue q;
    q.front=-1;q.rear=-1;
    int choice,n;

    printf("Enter max queue size : ");
    scanf("%d",&n);
    q.size=n;

    printf("1.Insert End\t2.Insert Front\t3.Delete End\t4.Delete Front\t5.Display\t0.Stop");

    do
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        if(choice==1)
            insertEnd(&q);
        else if(choice==2)
            insertFront(&q);
        else if(choice==3)
            deleteEnd(&q);
        else if(choice==4)
            deleteFront(&q);
        else if(choice==5)
            display(&q);
    }while(choice!=0);
}
