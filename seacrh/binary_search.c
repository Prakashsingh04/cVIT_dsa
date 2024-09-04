#include<stdio.h>
int binary_search(int arr[],int low, int high, int x)
{
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(x==arr[mid])
		{
			return mid;
		}
		if(x>arr[mid])
		{
			low=mid+1;
		}
		else{
			high=mid-1;
		}	
	}
	return -1;
}
void main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int n=10,j,key;
	
	printf("\nenter the key to search: ",&key);
	scanf("%d",&key);
	printf("\nyour array is:");
	for(j=0;j<n;j++)
	{
		printf(" %d\t",arr[j]);
	}
	int result=binary_search(arr,0,n-1,key);
	if(result==-1){
		printf("\nyour element is not found!!!");
	}
	else{
		printf("your element %d is found at index %d: ",key,result);
	}
}
