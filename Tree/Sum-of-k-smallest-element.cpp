// /* Method 1 : */

// #include <bits/stdc++.h>
// using namespace std;


// struct Node
// {
// 	int data;
// 	Node* left, * right;
// };


// struct Node *createNode(int data)
// {
// 	Node * new_Node = new Node;
// 	new_Node->left = NULL;
// 	new_Node->right = NULL;
// 	new_Node->data = data;
// 	return new_Node;
// }


// struct Node * insert(Node *root, int key)
// {
	
// 	if (root == NULL)
// 		return createNode(key);

	
// 	if (root->data > key)
// 		root->left = insert(root->left, key);

// 	else if (root->data < key)
// 		root->right = insert(root->right, key);

	
// 	return root;
// }


// int ksmallestElementSumRec(Node *root, int k, int &count)
// {
	
// 	if (root == NULL)
// 		return 0;
// 	if (count > k)
// 		return 0;

	
// 	int res = ksmallestElementSumRec(root->left, k, count);
// 	if (count >= k)
// 		return res;


// 	res += root->data;
// 	count++;
// 	if (count >= k)
// 	return res;

	
// 	return res + ksmallestElementSumRec(root->right, k, count);
// }


// int ksmallestElementSum(struct Node *root, int k)
// {
// int count = 0;
// return ksmallestElementSumRec(root, k, count);
// }


// int main()
// {

// 	Node *root = NULL;
// 	root = insert(root, 20);
// 	root = insert(root, 8);
// 	root = insert(root, 4);
// 	root = insert(root, 12);
// 	root = insert(root, 10);
// 	root = insert(root, 14);
// 	root = insert(root, 22);

// 	int k = 3;
// 	cout << ksmallestElementSum(root, k) <<endl;
// 	return 0;
// }


// Method 2: Efficient manner 


#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	int lCount;
	int Sum ;
	Node* left;
	Node* right;
};


struct Node *createNode(int data)
{
	Node * new_Node = new Node;
	new_Node->left = NULL;
	new_Node->right = NULL;
	new_Node->data = data;
	new_Node->lCount = 0 ;
	new_Node->Sum = 0;
	return new_Node;
}

struct Node * insert(Node *root, int key)
{
	
	if (root == NULL)
		return createNode(key);


	if (root->data > key)
	{
		
		root->lCount++;
		root->Sum += key;

		root->left= insert(root->left , key);
	}
	else if (root->data < key )
		root->right= insert (root->right , key );

	
	return root;
}


void ksmallestElementSumRec(Node *root, int k , int &temp_sum)
{
	if (root == NULL)
		return ;

	
	if ((root->lCount + 1) == k)
	{
		temp_sum += root->data + root->Sum ;
		return ;
	}

	else if (k > root->lCount)
	{
		
		temp_sum += root->data + root->Sum;

		
		k = k -( root->lCount + 1);
		ksmallestElementSumRec(root->right , k , temp_sum);
	}
	else 
		ksmallestElementSumRec(root->left , k , temp_sum );
}


int ksmallestElementSum(struct Node *root, int k)
{
	int sum = 0;
	ksmallestElementSumRec(root, k, sum);
	return sum;
}


int main()
{
	Node *root = NULL;
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 22);

	int k = 3;
	cout << ksmallestElementSum(root, k) << endl;
	return 0;
}
