// Method 1 (Uses Parent Pointer) 
/* Steps:

If right subtree of node is not NULL, then succ lies in right subtree. Do the following. 
Go to right subtree and return the node with minimum key value in the right subtree.
If right subtree of node is NULL, then succ is one of the ancestors. Do the following. 
Travel up using the parent pointer until you see a node which is left child of its parent. The parent of such a node is the succ.

*/

// #include <iostream>
// using namespace std;


// struct node {
// 	int data;
// 	struct node* left;
// 	struct node* right;
// 	struct node* parent;
// };

// struct node* minValue(struct node* node);

// struct node* inOrderSuccessor(struct node* root,struct node* n)
// {
	
// 	if (n->right != NULL)
// 		return minValue(n->right);
	
// 	struct node* p = n->parent;
// 	while (p != NULL && n == p->right) {
// 		n = p;
// 		p = p->parent;
// 	}
// 	return p;
// }

// struct node* minValue(struct node* node)
// {
// 	struct node* current = node;

// 	while (current->left != NULL) {
// 		current = current->left;
// 	}
// 	return current;
// }


// struct node* newNode(int data)
// {
// 	struct node* node = (struct node*)
// 		malloc(sizeof(
// 			struct node));
// 	node->data = data;
// 	node->left = NULL;
// 	node->right = NULL;
// 	node->parent = NULL;

// 	return (node);
// }

// struct node* insert(struct node* node,
// 					int data)
// {
// 	/* 1. If the tree is empty, return a new,
// 	single node */
// 	if (node == NULL)
// 		return (newNode(data));
// 	else {
// 		struct node* temp;

// 		/* 2. Otherwise, recur down the tree */
// 		if (data <= node->data) {
// 			temp = insert(node->left, data);
// 			node->left = temp;
// 			temp->parent = node;
// 		}
// 		else {
// 			temp = insert(node->right, data);
// 			node->right = temp;
// 			temp->parent = node;
// 		}

// 		/* return the (unchanged) node pointer */
// 		return node;
// 	}
// }

// int main()
// {
// 	struct node *root = NULL, *temp, *succ, *min;


// 	root = insert(root, 20);
// 	root = insert(root, 8);
// 	root = insert(root, 22);
// 	root = insert(root, 4);
// 	root = insert(root, 12);
// 	root = insert(root, 10);
// 	root = insert(root, 14);
// 	temp = root->left->right->right;

// 	succ = inOrderSuccessor(root, temp);
// 	if (succ != NULL)
// 		cout << "\n Inorder Successor of " << temp->data<< " is "<< succ->data;
// 	else
// 		cout <<"\n Inorder Successor doesn't exit";

// 	getchar();
// 	return 0;
// }


// Method-2 : Search from root

/* Steps: 

If right subtree of node is not NULL, then succ lies in right subtree. Do the following. 
Go to right subtree and return the node with minimum key value in the right subtree.
If right subtree of node is NULL, then start from the root and use search-like technique. Do the following. 
Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise, go to left side.

*/

#include <iostream>
using namespace std;


struct node 
{
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct node* minValue(struct node* node);

struct node* inOrderSuccessor(struct node* root,struct node* n)
{
	
	
	if (n->right != NULL)
		return minValue(n->right);

	struct node* succ = NULL;

	while (root->data != n->data) 
	{
		if (n->data < root->data) 
		{
			succ = root;
			root = root->left;
		}
		else
			root = root->right;
		
	}

	return succ;
}

 
struct node* minValue(struct node* node)
{
	struct node* current = node;

	// Loop down to find the leftmost leaf 
	while (current->left != NULL) 
	{
		current = current->left;
	}
	return current;
}

struct node* newNode(int data)
{
	struct node* node = (struct node*)
	malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return (node);
}


struct node* insert(struct node* node,int data)
{

	if (node == NULL)
		return (newNode(data));
	else
	{
		struct node* temp;


		if (data <= node->data) 
		{
			temp = insert(node->left, data);
			node->left = temp;
			temp->parent = node;
		}
		else
		{
			temp = insert(node->right, data);
			node->right = temp;
			temp->parent = node;
		}

		return node;
	}
}


int main()
{
	struct node *root = NULL, *temp, *succ, *min;

	
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);
	temp = root->left->right->right;
	
	succ = inOrderSuccessor(root, temp);
	if (succ != NULL)
		cout << "\n Inorder Successor of "
			<< temp->data << " is "<< succ->data;
	else
		cout <<"\n Inorder Successor doesn't exit";

	getchar();
	return 0;
}

