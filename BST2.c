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
void preorder(struct Node *root)
{
	if(root == NULL)
		return;
	printf("%d_",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct Node *root)
{
	if(root== NULL)
		return;
	inorder(root->left);
	printf("%d_",root->data);
	inorder(root->right);
}
void postorder(struct Node *root)
{
	if(root== NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d_",root->data);
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
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0;
}	

