#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[50];
    int rno, marks;
    struct node* next;
};
struct node* insertEnd(struct node* head, char s[], int num, int marks)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    strcpy(ptr->name,s);
    ptr->rno=num;
    ptr->marks=marks;
    ptr->next=NULL;

    struct node* p = head;

    if(p==NULL)
        return ptr;
    else
    {
        while(p->next!=NULL)
            p=p->next;

        p->next=ptr;
    }
    return head;
}
struct node* sort(struct node* head)
{
    struct node *ptr = head;
    struct node *ptr1 = ptr->next;

    char *tempname;
    int tempnum ,tempmarks;
    while(ptr!=NULL)
    {
        ptr1=ptr->next;
        while(ptr1!=NULL)
        {
            if(ptr->marks < ptr1->marks)
            {
                strcpy(tempname ,ptr->name);
                strcpy(ptr->name ,ptr1->name);
                strcpy(ptr1->name ,tempname);

                tempnum = ptr->rno;
                ptr->rno = ptr1->rno;
                ptr1->rno = tempnum;

                tempmarks = ptr->marks;
                ptr->marks = ptr1->marks;
                ptr1->marks = tempmarks;
            }
            ptr1=ptr1->next;
        }
        ptr=ptr->next;
    }
    return head;
}
void display(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%s %d %d\t",ptr->name,ptr->rno,ptr->marks);
        ptr = ptr->next;
    }
}
void main()
{
    int i,n;

    printf("Enter number of records : ");
    scanf("%d",&n);

    struct node* list = NULL;

    for(i=0;i<n;i++)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        char name[50];
        int num,marks;

        printf("Enter name,  roll number and marks of student %d : \n",(i+1));
        scanf("%s",&name);
        scanf("%d",&num);
        scanf("%d",&marks);
        ptr->next=NULL;

        list=insertEnd(list,name,num,marks);
    }

    display(list);

    list=sort(list);
    printf("\nList sorted by marks : ");
    display(list);

    struct node* second=list->next;
    printf("\nSecond largest result : %s,%d,%d",second->name,second->rno,second->marks);
}
