#include<stdio.h>
void insertion_sort(int arr[] ,int n){
	
	int i;
	for( i=1;i<n;++i)
	{
		int key = arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;	
		}
		arr[j+1]=key;
	}
}
void printt(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void main(){
	
	int arr[]={12,11,16,21,6,7,23};
	int n=sizeof(arr);
	insertion_sort(arr , n);
	printt(arr,n);
	

}
