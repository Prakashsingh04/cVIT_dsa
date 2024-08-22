#include<stdio.h>
#include<stdlib.h>
#define ARRAYSIZE 10
int queue[ARRAYSIZE];
int ch,x;
int front=-1;
int rear=-1;

void enqueue(int x)
{
	if(rear==ARRAYSIZE-1)
	{
		printf("\nqueue full!!");
	}
	else
	{
		if(front==-1 &&rear==-1)
		{
			front=front+1;
			rear=rear+1;
		}
		else
		{
			rear=rear+1;	
		}
		queue[rear]=x;	
	}
}
void dequeue()
{
	if(front==-1 && rear == -1)
	{
		printf("queue is empty");
	}
	else
	{
		int y=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=front +1;
		}
		printf("deleted element is %d",y);
	}
}
void display()
{
	int i;
	if(front==-1&& rear==-1)
	{
		printf("!!queue is already empty nothing to display!!!");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
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
