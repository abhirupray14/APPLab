#include<stdio.h>
#include<limits.h>
void maxHeapify(int *arr,int i)
{
	int j=i;
	while(j > 0)
	{
		int x = (j-1)/2;
		if(arr[x] < arr[j])
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
void printMaxHeap(int *arr,int n)
{
	int i = 0;
	while(i <= n)
	{
		if(arr[i] != INT_MIN)
			printf("%d ",arr[i]);
		else
			break;
		i++;
	}
	printf("\n");
}
void delMax(int *arr,int n)
{
	// n is the max size of the array
	int lastIndex = n-1;
	int top = arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i] == INT_MIN)
		{
			lastIndex = i-1;
			break;
		}
	}
	arr[0] = arr[lastIndex];
	arr[lastIndex] = INT_MIN;
	int i=0;
	while(i < lastIndex)
	{
		int lC = 2*i + 1;
		int rC = 2*i + 2;
		int maxIndex = -1;
		if((lC >= lastIndex) && (rC >= lastIndex))
			break;
		else if(rC >= lastIndex)
		{
			maxIndex = lC;
		}
		else
			maxIndex = (arr[lC] > arr[rC]) ?  lC : rC;
		// check with the parent.
		if(arr[i] < arr[maxIndex])
		{
			int temp = arr[i];
			arr[i] = arr[maxIndex];
			arr[maxIndex] = temp;
			i = maxIndex;
		}
		else 
			break;
	}
}

int main()
{
	// Max Heap.
	// Number of elements in Max Heap.
	int n;
	scanf("%d",&n);
	int d;
	scanf("%d",&d);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = INT_MIN;
	}
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		arr[i] = temp;
		maxHeapify(arr,i);
		printMaxHeap(arr,i);
	}
	while(d--)
	{

		delMax(arr,n);
		printMaxHeap(arr,n);
	}
	return 0;
}
