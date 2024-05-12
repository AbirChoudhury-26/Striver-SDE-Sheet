// Method-1

/* Steps:

Traverse the tree, while traversing store the value of a node in the set
If for a current node with value x, there exists a y for which x + y = sum then check it using set and return the pair.

*/


// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
// 	int data;
// 	struct Node *left, *right;
// };

// Node* NewNode(int data)
// {
// 	Node* temp = (Node*)malloc(sizeof(Node));
// 	temp->data = data;
// 	temp->left = NULL;
// 	temp->right = NULL;
// 	return temp;
// }

// Node* insert(Node* root, int key)
// {
// 	if (root == NULL)
// 		return NewNode(key);
// 	if (key < root->data)
// 		root->left = insert(root->left, key);
// 	else
// 		root->right = insert(root->right, key);
// 	return root;
// }

// bool findpairUtil(Node* root, int sum,
// 				unordered_set<int>& set)
// {
// 	if (root == NULL)
// 		return false;

// 	if (findpairUtil(root->left, sum, set))
// 		return true;

// 	if (set.find(sum - root->data) != set.end()) {
// 		cout << "Pair is found (" << sum - root->data
// 			<< ", " << root->data << ")" << endl;
// 		return true;
// 	}
// 	else
// 		set.insert(root->data);

// 	return findpairUtil(root->right, sum, set);
// }

// void findPair(Node* root, int sum)
// {
// 	unordered_set<int> set;
// 	if (!findpairUtil(root, sum, set))
// 		cout << "Pairs do not exit" << endl;
// }


// int main()
// {
// 	Node* root = NULL;
// 	root = insert(root, 15);
// 	root = insert(root, 10);
// 	root = insert(root, 20);
// 	root = insert(root, 8);
// 	root = insert(root, 12);
// 	root = insert(root, 16);
// 	root = insert(root, 25);
// 	root = insert(root, 10);

// 	int sum = 28;
// 	findPair(root, sum);

// 	return 0;
// }


// Method-2 : Using 2 Pointer Approach


/* Approach :

The main idea is to find the Inorder Traversal of the BST and store it in a vector. We know that Inorder traversal of BST will be in sorted order.Now we will Apply Two pointers Technique to find that whether there exist two elements in the vector that sums up to the given value.

Algorithm:

1. First find the Inorder traversal of the Given BST and store it in a vector  (Let v).
2. Take two pointers i and j. Keep i at the start of v and j at the end of the v.  
   i.   Now, if sum of elements at the ith index and jth index is greater that the given element then decrement j, 
   ii.  If sum of elements at the ith index and jth index is less that the given element then increment i,
   iii. Else, these two elements are our required answer. 

*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left, *right;
};

TreeNode* NewNode(int data)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

TreeNode* insert(TreeNode* root, int key)
{
	if (root == NULL)
		return NewNode(key);
	if (key < root->val)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

void inorder(TreeNode* root, vector<int>& v)
{
	if (root == NULL) {
		return;
	}
	inorder(root->left, v);
	v.push_back(root->val);
	inorder(root->right, v);
}

pair<int, int> findTarget(TreeNode* root, int k)
{

	vector<int> v;
	inorder(root, v);
	int n = v.size();
	int i = 0;
	int j = n - 1;
	while (j > i) {
		if (v[i] + v[j] == k) {
			return { v[i], v[j] };
		}
		else if (v[i] + v[j] > k) {
			j--;
		}
		else {
			i++;
		}
	}
	return { -1, -1 };
}

int main()
{

	TreeNode* root = NULL;
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 12);
	root = insert(root, 16);
	root = insert(root, 25);
	root = insert(root, 10);

	int k = 28;

	auto a = findTarget(root, k);
	cout << a.first << " " << a.second << endl;
}
