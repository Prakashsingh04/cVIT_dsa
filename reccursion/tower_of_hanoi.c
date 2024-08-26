#include<stdio.h>
void hanoi(int n,char s,char d,char temp)
{
	if(n==1)
	{
		printf("\nmove disk 1 form %c to %c ",s,d);
		return;
	}
	hanoi(n-1,s,temp,d);
	printf("\nmove disk %d form %c to %c ",n,s,d);
	hanoi(n-1,temp,d,s);
}
void main(){
	
	int n;
	printf("\nenter the number of disk you want:");
	scanf("%d",&n);
	
	hanoi(n,'A','C','B');
}

