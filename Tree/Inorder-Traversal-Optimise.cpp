// Approach 1: Using Stack

/*

Create an empty stack (say S).
Initialize the current node as root.
Push the current node to S and set current = current->left until current is NULL
If current is NULL and the stack is not empty then:
Pop the top item from the stack.
Print the popped item and set current = popped_item->right 
Go to step 3.
If current is NULL and the stack is empty then we are done.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void inOrder(struct Node* root)
{
	stack<Node*> s;
	Node* curr = root;

	while (curr != NULL || s.empty() == false) {
		
		while (curr != NULL) {

			s.push(curr);
			curr = curr->left;
		}


		curr = s.top();
		s.pop();

		cout << curr->data << " ";
		curr = curr->right;

	}
}


int main()
{

	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	inOrder(root);
	return 0;
}
