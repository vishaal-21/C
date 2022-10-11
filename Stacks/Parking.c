#include<stdio.h>
typedef struct
{
	int plate;
	int count;
}Car;

int arrival(int arr[],int top,int n,int* i,Car c[])
{
	if((top+1)>(n-1))
	{
		printf("Parking is full\n");
	}
	else
	{
		arr[++top]=c[*i].plate;
		*i=*i+1;
	}
	return top;
}

int departure(int arr[],int top,int n,int* i,Car c[])
{
	if(top==-1)
	{
		printf("Parking is empty\n");
	}
	else
	{
		int pos;
		printf("Enter position form where car has to be removed : ");
		scanf("%d",&pos);

		for(*i=(pos-1);*i<(n-1);(*i)++)
		{
			arr[*i]=arr[(*i)+1];
			c[*i].count++;
		}
	}
	*i=*i-1;
	return --top;
}

void display(int top, int arr[])
{
	int i;
	printf("Parking Lot status\n");
	for(i=top;i>=0;i--)
		printf("%d. %d\n",(i+1),arr[i]);
}

void main()
{
	int n=10,top=-1,a=0;
	int *i=&a;
	char choice='9';

	Car c[n];
	int arr[n];
	while(choice!='0')
	{
		printf("A. Arrival\t");
		printf("D. Departure\t");
		printf("3. Display\t");
		printf("0 to stop\n");
		scanf("%c",&choice);

		if(choice == 'A')
		{
			printf("Enter license plate number : ");
			scanf("%d",&c[a].plate);
			top=arrival(arr,top,n,i,c);
		}
		else if(choice == 'D')
		{
			top=departure(arr,top,n,i,c);
		}
		else if(choice=='3')
			display(top,arr);
	}
}