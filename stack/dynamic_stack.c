#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}SNODE;
SNODE * init(SNODE *S){
	return (NULL);
}

SNODE *push(SNODE *S,int item){
	 SNODE *newnode=(SNODE*)malloc(sizeof(struct node));
	 newnode->data=item;
	 if (S=NULL){
	 	newnode->next=NULL;
	 	S=newnode;
	 }
	 else
	 {
	 	newnode->next=S;
	 	S=newnode;
	 }
	 return(S);
}
SNODE *pop(SNODE *S){
	SNODE *temp;
	if(S==NULL){
		printf("\nstack is empty!!!");
	}
	else{
		temp=S;
		S=S->next;
		printf("\n%d is popped!!!\n",temp->data);
		temp->next=NULL;
		free(NULL);
	}
	return(S);
}
int isEmpty(SNODE *S)
{
	if(S==NULL)
	{
		return 1;
	}
	else 
	return 0;
}
int peek(SNODE *S)
{
	return (S->data);
}
void display(SNODE *S)
{
	SNODE *temp;
	temp=S;
	while(temp!=NULL){
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}
void main(){
	int n,ch;
	SNODE *S;
	S=init(S);
	do{
			printf("\nSTACK MENU\n1)push\n2)pop\n3)peek\n4)display\n5)exit");
		printf("\nenter your choise: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("\nenter a number to push: ");
					scanf("%d",&n);
						S=push(S,n);
						printf("\n%d pushed in stack!\n",n);
					break;
			
			case 2:
					if(!isEmpty(S))
					{
						S=pop(S);
						printf("\n%d popped\n",n);
					}
					else
					{
						printf("stack underflow!!!\n");
					}
					break;
			case 3:
					if(!isEmpty(S))
					{
						n=peek(S);
						printf("\npeak value=%d\n",S);
					}
					else 
					printf("\n!!stack underflow!!\n");
					break;
					
					display(S);
					break;
			case 4:
					
					display(S);
					break;
			default:
					printf("wrong choise!!!! choose again!!!\n");
		}
		
	}while(ch!=5);	
}
