#include<stdio.h>
#define SIZE 100
void insertion_sort(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(temp<arr[j] && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
int main()
{
	int arr[SIZE],i,n;
	printf("Enter the number of elements in the array \n");
	scanf("%d",&n);
	printf("Enter the elements in the array \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion_sort(arr,n);
	printf("The sorted array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return(0);
}