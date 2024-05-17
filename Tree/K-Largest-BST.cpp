// Approach : Using Morris Traversal

/* Advantages: The special thing about Morris traversal is that we can do Inorder traversal without using stack or recursion which saves us memory consumed by stack or recursion call stack.
               Reverse Morris traversal is just the reverse of Morris traversal which is majorly used to do Reverse Inorder traversal with constant O(1) extra memory consumed as it does not uses any Stack or Recursion.*/

               
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};


Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->right = temp->left = NULL;
	return temp;
}

Node* KthLargestUsingMorrisTraversal(Node* root, int k)
{
	Node* curr = root;
	Node* Klargest = NULL;

	// count variable to keep count of visited Nodes
	int count = 0;

	while (curr != NULL) {
		// if right child is NULL
		if (curr->right == NULL) {

			// first increment count and check if count = k
			if (++count == k)
				Klargest = curr;

			// otherwise move to the left child
			curr = curr->left;
		}

		else {

			// find inorder successor of current Node
			Node* succ = curr->right;

			while (succ->left != NULL && succ->left != curr)
				succ = succ->left;

			if (succ->left == NULL) {

				// set left child of successor to the
				// current Node
				succ->left = curr;

				// move current to its right
				curr = curr->right;
			}

			// restoring the tree back to original binary
			// search tree removing threaded links
			else {

				succ->left = NULL;

				if (++count == k)
					Klargest = curr;

				// move current to its left child
				curr = curr->left;
			}
		}
	}

	return Klargest;
}

int main()
{
	
	Node* root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(10);

	cout << "Finding K-th largest Node in BST : "
		<< KthLargestUsingMorrisTraversal(root, 2)->data;

	return 0;
}
