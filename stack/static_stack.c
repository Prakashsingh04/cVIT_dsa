//static stack using array
#include<stdio.h>
#define MAX 5
typedef struct stack
{
	int data[MAX];
	int top;
} stack;

void init(stack *s)
{
	s->top=-1;
}

int isEmpty(stack *s)
{
	if(s->top==-1)
		return 1;
	return 0;
}

int isFull(stack *s)
{
	if(s->top==MAX-1)
		return 1;
	return 0;
}
void push(stack *s,int x)
{
	s->top=s->top+1;
	s->data[s->top]=x;
}

int pop(stack *s)
{
	int x=s->data[s->top];
	s->top=s->top-1;
	return x;
}
int peek(stack *s)
{
	return (s->data[s->top]);
}

void display(stack *s)
{
	int i;
	printf("\n");
	for(i=s->top;i>=0;i--)
	{
		printf("\t%d\t",s->data[i]);		
	}
}

void main()
{
	stack s;
	int x,ch;
	init(&s);
	do{
		printf("\n1)push\n2)pop\n3)display\n4)peek\n5)exit");
		printf("\nenter your choise: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("\nenter a number to push: ");
					scanf("%d",&x);
					if(!isFull(&s))
					{
						push(&s,x);
						printf("\n%d pushed in stack!\n",x);
					}
					else
					{
						printf("\nSTACK OVERFLOW!!!!\n");
					}
					break;
			
			case 2:
					if(!isEmpty(&s))
					{
						x=pop(&s);
						printf("\n%d popped\n",x);
					}
					else
					{
						printf("stack underflow!!!\n");
					}
					break;
			case 3:
					display(&s);
					break;
			case 4:
					if(!isEmpty(&s))
					{
						x=peek(&s);
						printf("\npeak value=%d\n",x);
					}
					else 
					printf("\n!!stack underflow!!\n");
					break;
			default:
					printf("wrong choise!!!! choose again!!!\n");
		}
		
	}while(ch!=5);	
}
