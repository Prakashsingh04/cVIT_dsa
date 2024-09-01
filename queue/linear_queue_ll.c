#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
}*front=NULL,*rear=NULL;
void enqueue(int x)
{
	struct node *newnode=malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	if(front==NULL && rear==NULL)
	{	
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;	
		rear=newnode;
	}
}
void dequeue()
{
	struct node * temp;
	if(front==NULL)
	{
		printf("queue is empty!!");
	}
	else
	{
		temp=front;
		printf("\n%d is deleted form queue\n",front->data);
		front=front->next;
		if(front==NULL	)
		{
			rear=NULL;
		}
		free(NULL);
	}
}
void display()
{
	struct node *temp=front;
	while(temp)
	{
		printf("%d ->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	display();
	printf("\nafter the dequeue!!\n");
	dequeue();
	display();
	printf("\nafter second dequeue!!\n");
	dequeue();
	display();
	//change main according to need!!!!!:)
}
