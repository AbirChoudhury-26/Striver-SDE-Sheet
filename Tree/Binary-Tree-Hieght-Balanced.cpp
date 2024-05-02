// /* Approach 1:

// Get the height of left and right subtrees using dfs traversal. 
// Return true if the difference between heights is not more than 1.
// Also left and right subtrees are balanced, otherwise return false.

// */

// #include <bits/stdc++.h>
// using namespace std;


// class Node {
// public:
// 	int data;
// 	Node* left;
// 	Node* right;
// 	Node(int d)
// 	{
// 		int data = d;
// 		left = right = NULL;
// 	}
// };

// int height(Node* node)
// {
// 	// base case tree is empty
// 	if (node == NULL)
// 		return 0;

// 	// If tree is not empty then
// 	// height = 1 + max of left height
// 	// and right heights
// 	return 1 + max(height(node->left), height(node->right));
// }


// bool isBalanced(Node* root)
// {
// 	// for height of left subtree
// 	int lh;

// 	// for height of right subtree
// 	int rh;

// 	// If tree is empty then return true
// 	if (root == NULL)
// 		return 1;

// 	// Get the height of left and right sub trees
// 	lh = height(root->left);
// 	rh = height(root->right);

// 	if (abs(lh - rh) <= 1 && isBalanced(root->left)
// 		&& isBalanced(root->right))
// 		return 1;

// 	// If we reach here then tree is not height-balanced
// 	return 0;
// }

// // Driver code
// int main()
// {
// 	Node* root = new Node(1);
// 	root->left = new Node(2);
// 	root->right = new Node(3);
// 	root->left->left = new Node(4);
// 	root->left->right = new Node(5);
// 	root->left->left->left = new Node(8);

// 	if (isBalanced(root))
// 		cout << "Tree is balanced";
// 	else
// 		cout << "Tree is not balanced";
// 	return 0;
// }


// Method-2 : Using Recusrion Only

// Working Principle : Calculating the height in the same recursion rather than calling a height() function separately.

/* Steps:

For each node make two recursion calls – one for left & other for the right subtree. 
Based on the heights returned from the recursion calls, decide if the subtree whose root is the current node is height-balanced or not. 
If it is balanced then return the height of that subtree. Otherwise, return -1 to denote that the subtree is not height-balanced.

*/


#include <bits/stdc++.h>
using namespace std;


struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	Node(int k)
	{
		key = k;
		left = right = NULL;
	}
};

// Function to check if tree is height balanced
int isBalanced(Node* root)
{
	if (root == NULL)
		return 0;
	int lh = isBalanced(root->left);
	if (lh == -1)
		return -1;
	int rh = isBalanced(root->right);
	if (rh == -1)
		return -1;

	if (abs(lh - rh) > 1)
		return -1;
	else
		return max(lh, rh) + 1;
}


int main()
{
	Node* root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(30);
	root->right->left = new Node(15);
	root->right->right = new Node(20);

	if (isBalanced(root) > 0)
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}
