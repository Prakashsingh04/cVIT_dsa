#include<stdio.h>
int linear_search(int arr[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			return i+1;
		}
	}
	return -1;
}
int main()
{
	int key,j,n=9;
	int arr[]={1,2,3,4,5,6,7,8,9};
	printf("\nenter the key to search: ",&key);
	scanf("%d",&key);
	printf("your array is:");
	for(j=0;j<n;j++)
	{
		printf(" %d\t",arr[j]);
	}
	int result=linear_search(arr,n,key);
	if(result==-1)
	{
		printf("\nyour element %d is not present!!!\n",key);
	}
	else{
		printf("\nelement %d is at position number: %d",key,result);
	}

}
