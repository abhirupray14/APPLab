#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node* insertNode(struct Node* head,int elem)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = elem;
	newNode->next = NULL;
	if(head == NULL)
	{
		head = newNode;
		return head;
	}
	struct Node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}
void printLL(struct Node* head)
{
	struct Node* temp = head;
	if(!head) return;
	while(temp)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
struct Node* reverse(struct Node *head,struct Node* nextNode)
{
	if(head == NULL)
		return head;
	struct Node *curr = head;
	struct Node *prev = nextNode;
	while(curr != nextNode)
	{
		struct Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}
struct Node* reverseinGroups(struct Node* head,int k)
{
	if(head == NULL)
		return head;
	int count = 1;
	struct Node* temphead = head;
	struct Node* temp = head;
	int loopcount = 0;
	while(temp->next != NULL)
	{
		count += 1;
		temp=temp->next;
		if(count % k == 0)
		{
			loopcount += 1;
			struct Node *temp1 = temphead;
			temphead = reverse(temphead,temp->next);
			if(loopcount == 1)
				head = temphead;
			temp = temp1;
		}
	}
	return head;

}
int main()
{
	int n;
	printf("Enter the number of elements you want to insert:");
	scanf("%d",&n);
	int k;
	printf("Enter the group size");
	scanf("%d",&k);
	struct Node* head = NULL;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		head = insertNode(head,temp);
	}
	printf("The Linked List before reversal in groups:\n");
	printLL(head);
	head = reverseinGroups(head,k);
	printLL(head);
	return 0;
}

