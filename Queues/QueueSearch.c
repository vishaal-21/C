#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int arr[50];
    int front, rear, size;
}Queue;
void insertcq(Queue* q)
{
    int item;

    if((q->front==0 && q->rear==q->size-1) || (q->front==q->rear+1))
        printf("Queue is full");
    else
    {
        if(q->front==-1)
            q->front=0;

        printf("Enter number : ");
        scanf("%d",&item);

        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear] = item;
    }
}
void deletecq(Queue* q)
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
            q->front=(q->front+1)%q->size;
    }
}
void displaycq(Queue* q)
{
    int i;

    printf("\nQueue is:\n");
    for(i=q->front; i!=q->rear; i=(i+1)%(q->size))
        printf("%d\n",q->arr[i]);
    printf("%d\n",q->arr[i]);
}
int search(Queue* q,int ele)
{
    int i,flag=0;
    for(i=q->front; i!=q->rear; i=(i+1)%(q->size))
    {
        if(ele==i)
        {
            flag=1;
            break;
        }
    }

    if(ele==q->arr[i])
        flag=1;

    return flag;
}
void main()
{
    Queue q;
    q.front=-1;q.rear=-1;
    int n,key,choice;

    printf("Enter max queue size : ");
    scanf("%d",&n);
    q.size=n;

    printf("1. Enqueue\t2.Dequeue\t3.Display\t0.Stop");

    do
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            insertcq(&q);
        }
        else if(choice==2)
        {
            deletecq(&q);
        }
        else if(choice==3)
            displaycq(&q);
    }while(choice!=0);

    printf("Enter element to be searched : ");
    scanf("%d",&key);

    int result=search(&q,key);

    if(result)
        printf("Element found");
    else
        printf("Not found");
}
