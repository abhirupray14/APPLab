#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node* constructBST(struct Node *root,int temp)
{
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = temp;
	newNode->left = NULL;
	newNode->right = NULL;
	struct Node *child = root;
	struct Node *parent  = NULL;
	while(child != NULL)
	{
		parent = child;
		if(temp <= child->data)
			child = child->left;
		else
			child = child ->right;
	}
	if(parent == NULL)
		return newNode;
	else if(temp <= parent ->data)
		parent ->left = newNode;
	else
		parent->right = newNode;
	return root;
}
bool search(struct Node* root,int elem)
{
	struct Node *temp = root;
	while(temp != NULL)
	{
		if(elem == temp->data)
			return 1;
		else if(elem < temp->data)
			temp =temp ->left;
		else
			temp = temp->right;
	}
	return 0;
}
int main()
{
	int n; // Number of elemenets in the BST
	scanf("%d",&n);
	struct Node *root = NULL;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		root = constructBST(root,temp);
	}
	int s;//No of search operations.
	scanf("%d",&s);
	for(int i=0;i<s;i++)
	{
		int d;
		scanf("%d",&d);
		if(search(root,d))
			printf("Element Found\n");
		else
			printf("Element not found\n");
	}
	return 0;
}	

