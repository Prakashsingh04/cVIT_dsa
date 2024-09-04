#include<stdio.h>
#include<stdlib.h>
#define ARRAYSIZE 10
int cqueue[ARRAYSIZE];
int ch,x;
int front=-1;
int rear=-1;
void enqueue(int x)
{
	if(rear==(rear+1)%ARRAYSIZE)
	{
		printf("\nqueue is full!!!");
	}
	else
	{
		rear=(rear+1)%ARRAYSIZE;
		cqueue[rear]=x;
		if(front==-1)
		{
			front=front+1;
		}
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("\nqueue is empty!!!");
	}	
	else
	{
		printf("\nthe dequeue element is %d",cqueue[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%ARRAYSIZE;
		}
	}
}

void display()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("!!queue is already empty nothing to display!!!");
	}
	else
	{
		while(i!=rear)
		{
			printf("%d\t",cqueue[i]);
			i=(i+1)%ARRAYSIZE;
		}
		//last element
		printf("%d\n",cqueue[rear]);
	}
}
void main()
{
	while(1)
	{
		
		printf("\n1)enqueue\n2)dequeue\n3)display\n4)exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		
			case 1:
					printf("\nenter the element:\t");
					scanf("%d",&x);
					enqueue(x);
					break;
			case 2:
					dequeue();
					break;
			case 3: display();
					break;
			case 4:
					exit(0);
			default:
					printf("\nwrong choise!!!!");	
		}
	}
}
