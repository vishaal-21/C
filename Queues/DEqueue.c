// still working

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int arr[50];
    int front, rear, size;
}Queue;
int isEmpty(Queue *q)
{
    if(q->front==-1)
        printf("Queue is empty");
}
int isFull(Queue *q)
{
    if((q->front==0 && q->rear==q->size-1) || (q->front==q->rear+1))
        return 1;
    else
        return 0;
}
void insertFront(Queue *q)
{

}
void insertEnd(Queue* q)
{
    int item;
    if(isFull(q))
        printf("Queue is full");
    else
    {
        if(q->front==-1)
            q->front=0;

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
    {
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else
            q->front=(q->front+1)%q->size;
    }
}
void deleteEnd(Queue *q)
{

}
void display(Queue* q)
{
    int i;

    printf("\nQueue is:\n");
    for(i=q->front; i!=q->rear; i=(i+1)%(q->size))
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

    printf("1. Insert End\t2. Insert Front\t3. Delete End\t4. Delete Front\t0. Stop");

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
    }while(choice!=0);
}
