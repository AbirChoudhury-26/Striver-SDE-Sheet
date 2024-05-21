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

// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
// 	int data;
// 	struct Node* left;
// 	struct Node* right;
// 	Node(int data)
// 	{
// 		this->data = data;
// 		left = right = NULL;
// 	}
// };

// void inOrder(struct Node* root)
// {
// 	stack<Node*> s;
// 	Node* curr = root;

// 	while (curr != NULL || s.empty() == false) {
		
// 		while (curr != NULL) {

// 			s.push(curr);
// 			curr = curr->left;
// 		}


// 		curr = s.top();
// 		s.pop();

// 		cout << curr->data << " ";
// 		curr = curr->right;

// 	}
// }


// int main()
// {

// 	struct Node* root = new Node(1);
// 	root->left = new Node(2);
// 	root->right = new Node(3);
// 	root->left->left = new Node(4);
// 	root->left->right = new Node(5);

// 	inOrder(root);
// 	return 0;
// }



#include <bits/stdc++.h>
using namespace std;


struct tNode {
	int data;
	struct tNode* left;
	struct tNode* right;
};


void inOrder(struct tNode* root)
{
	struct tNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {
			cout << current->data << " ";
			current = current->right;
		}
		else {

			pre = current->left;
			while (pre->right != NULL
				&& pre->right != current)
				pre = pre->right;

			if (pre->right == NULL) {
				pre->right = current;
				current = current->left;
			}
			else {
				pre->right = NULL;
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}

struct tNode* newtNode(int data)
{
	struct tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Driver code
int main()
{
	struct tNode* root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	inOrder(root);

	return 0;
}

