/* Approach 1 (No recursion/ stack is used):

Approach 1 

The approach used is based on using an unordered set to keep track of visited nodes and a while loop to traverse the tree. 

Initialize a pointer temp to the root node of the binary tree.
Initialize an empty unordered set visited to keep track of visited nodes.
While temp is not null and temp is not already visited (i.e., temp is not in visited set):
a. If temp has a left child and the left child is not already visited, set temp to the left child.
b. Else if temp has a right child and the right child is not already visited, set temp to the right child.
c. Else, print the data of the current node temp, add temp to visited set, and set temp to the root node.
Return from the function.
*/

#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	struct Node *left, *right;
};

void postorder(struct Node* head)
{
	struct Node* temp = head;
	unordered_set<Node*> visited;
	while (temp && visited.find(temp) == visited.end()) {

		if (temp->left && 
		visited.find(temp->left) == visited.end())
			temp = temp->left;

		else if (temp->right && 
		visited.find(temp->right) == visited.end())
			temp = temp->right;

		else {
			printf("%d ", temp->data);
			visited.insert(temp);
			temp = head;
		}
	}
}

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int main()
{
	struct Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	postorder(root);
	return 0;
}
