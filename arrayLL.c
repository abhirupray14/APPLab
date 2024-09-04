#include<stdio.h>
void insert(long long *arr,int *head,int elem,int *freeplace)
{
    int temp = *head;
    if(*freeplace == 0)
    {
        printf("There is not a single place to insert a element\n");
        return;
    }
    if(temp == -1)
    {
        temp = temp + 1;
        arr[temp] = elem*10;
        *freeplace -= 1;
        *head = temp;
        return;
    }
    int temp1 = 0;
    // This loop is to find the empty block
    while(arr[temp1] != -1)
    {
        temp1++;
    }
    while(arr[temp] % 10 != 0)
    {
        int rem = arr[temp] % 10;
        temp = rem; 
    }
    arr[temp] = (arr[temp]) + (temp1);
    arr[temp1] = (elem*10);
    *freeplace -= 1;
    return;

}
void pasteList(long long *arr,int *head)
{
    int temp = *head;
    int count = 0;
    while((arr[temp] % 10) != 0)
    {
        long long data = arr[temp]/10;
        printf("%lld " , data);
        int rem = arr[temp] % 10;
        temp = rem;
        count += 1;
    }
    printf("%lld",arr[temp]/10);
    printf("\n");
    return;
}
void deleteList(long long *arr, int *head,int position,int *freeplace)
{
    int temp = *head;
    if(*freeplace == 10)
    {
        printf("No element to delete in the linkedlist:\n");
        return;
    }
    if(position == 0)
    {
        long long  data = arr[temp]/10;
        printf("%lld is deleted from the linked list.\n", data);
        temp = arr[temp] % 10;
        arr[*head] = -1;
        *head = temp;
        *freeplace += 1;
        return;
    }
    // loop to find the previous position just before deleted element.
    int count = 0;
    while(count != position-1)
    {
        int rem = arr[temp] % 10;
        count += 1;
        temp = rem;
    }
    int nextIndex = arr[temp] % 10;
    long long fdata = arr[temp];
    int nnextIndex = arr[nextIndex] % 10;
    long long data = arr[nextIndex]/10;
    arr[temp] = (arr[temp]/10)*10 + (nnextIndex);
    arr[nextIndex] = -1;
    printf("%lld got deleted from linkedList\n",data);
    *freeplace += 1;
    return;
}
int main()
{
    long long arr[10];
    int freeplace = 10;
    for(int i=0;i<10;i++)
    {
        arr[i] = -1;
    }
    int head = -1;
    while(1)
    {
        printf("Enter 1 to insert an element and 2 to delete an element and 3 to print the linked list:\n");
        int n;
        scanf("%d", &n);
        if(n == 1)
        {
            printf("Enter the element you want to insert : ");
            int elem;
            scanf("%d",&elem);
            insert(arr,&head,elem,&freeplace);
        }
        else if(n == 2)
        {
            int index;
            printf("Enter which positioned element you want to delete : ");
            scanf("%d",&index);
            deleteList(arr, &head, index,&freeplace);
        }
        else if(n == 3)
        {
            pasteList(arr,&head);
        }
        else
        {
            return 0;
        }
        
    }
    return 0;

    
}