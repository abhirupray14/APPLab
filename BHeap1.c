#include<stdio.h>
#include<limits.h>
void heapify(int *arr,int i)
{
	int j = i;
	while(j > 0)
	{
		int x = (j-1)/2;
		if(arr[x] > arr[j])
		{
			int temp = arr[x];
			arr[x] = arr[j];
			arr[j] = temp;
			j = x;
		}
		else
			break;
	}
}
void heapDel(int *arr,int n)
{
	int r = 0;
	while(r < n)
	{
		int lC= 2*r+1;
		int rC = 2*r + 2;
		int minIndex;
		if(lC > n)
		{
			break;
		}
		else if(rC > n)
		{
			minIndex = lC;
		}
		else
		{
			if(arr[lC] < arr[rC])
				minIndex = lC;
			else
				minIndex = rC;
		}
		if(arr[minIndex] < arr[r])
		{
			int temp = arr[minIndex];
			arr[minIndex] = arr[r];
			arr[r] = temp;
			r = minIndex;
		}
		else 
			break;
		
	}
}
void printHeap(int *arr,int i)
{
	int j=0;
	while(j <= i)
	{
		printf("%d ",arr[j]);
		j++;
	}
	printf("\n");
}
void delTop(int *arr,int n)
{
	int elem = arr[0];
	int lastIndex =n-1;
	for(int i=0;i<n;i++)
	{
		if(arr[i] == INT_MAX)
		{
			lastIndex = i-1;
			break;
		}
	}
	arr[0] = arr[lastIndex];
        arr[lastIndex] = INT_MAX;
	heapDel(arr,lastIndex-1);
	printHeap(arr,lastIndex-1);
}
int main()
{
	// MinHeap
	int n;// No. of elements in minHeap
	scanf("%d",&n);
	int d;//Number of elements to delete from MinHeap.
	scanf("%d",&d);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = INT_MAX;
	}
	int i=0;
	while(i < n)
	{
		int temp;
		scanf("%d",&temp);
		arr[i] = temp;
		heapify(arr,i);
		printHeap(arr,i);
		i++;
	}
	int j = 1;
	while(j <= d)
	{
		delTop(arr,n);
		j++;
	}
	return 0;
}	
