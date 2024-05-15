#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	int count;
	struct node *left, *right;
};


struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->count = 1;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << "("
			<< root->count << ") ";
		inorder(root->right);
	}
}


struct node* insert(struct node* node, int key)
{

	if (node == NULL) return newNode(key);
	
	if (key == node->key)
	{
	(node->count)++;
		return node;
	}

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}


struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}


struct node* deleteNode(struct node* root, 
								int key)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than 
	// the root's key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key
	else
	{
		// If key is present more than once, 
		// simply decrement count and return
		if (root->count > 1)
		{
			(root->count)--;
			return root;
		}

		// ElSE, delete the node

		// node with only one child or no child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = minValueNode(root->right);

		root->key = temp->key;
		root->count = temp->count;
	

		temp->count = 0; 

		root->right = deleteNode(root->right,temp->key);
	}
	return root;
}

// Driver Code
int main()
{

	struct node *root = NULL;
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 9);
	root = insert(root, 11);
	root = insert(root, 10);
	root = insert(root, 12);
	root = insert(root, 12);

	cout << "Inorder traversal of the given tree "
		<< endl;
	inorder(root);

	cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 12\n" ;
	root = deleteNode(root, 12);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 9\n";
	root = deleteNode(root, 9);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	return 0;
}


