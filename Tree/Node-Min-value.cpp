/* Approach 1: Using Indorder Traversal & Making vector.Then returning the min value*/


#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}


struct node* insert(struct node* node, int data)
{
	
	if (node == NULL)
		return (newNode(data));
	else {

		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);

		
		return node;
	}
}


void inorder(struct node* node, vector<int>& sortedInorder)
{
	if (node == NULL)
		return;

	inorder(node->left, sortedInorder);

	
	sortedInorder.push_back(node->data);

	inorder(node->right, sortedInorder);
}


int main()
{
	struct node* root = NULL;
	root = insert(root, 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 4);
	insert(root, 5);

	vector<int> sortedInorder;
	inorder(root,sortedInorder); 
	printf("\n Minimum value in BST is %d",
		sortedInorder[0]);
	getchar();
	return 0;
}
