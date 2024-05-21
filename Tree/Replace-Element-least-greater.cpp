#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node {
	int data;
	Node *left, *right;
};


Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

Node* insert(Node* root, int val, int& suc)
{

	if (!root)
		return newNode(val);

	if (val >= root->data)
		root->right = insert(root->right, val, suc);

	else {
		suc = root->data;
		root->left = insert(root->left, val, suc);
	}
	return root;
}

void replace(int arr[], int n)
{
	Node* root = nullptr;
	// start from right to left
	for (int i = n - 1; i >= 0; i--) {
		int suc = -1;
		// insert current element into BST and
		// find its inorder successor
		root = insert(root, arr[i], suc);
		arr[i] = suc;
	}
}

int main()
{
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
				43, 3, 91, 93, 25, 80, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);
	replace(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

