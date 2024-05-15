// Method-1 : Basic Approach

// #include<bits/stdc++.h>
// using namespace std;

// struct Node{
// 	int data;
// 	Node* left;
// 	Node* right;
// 	Node(int data){
// 		this->data = data;
// 		this->left = this->right = NULL;
// 	}
// };

// Node* newNode(int data){
// 	return new Node(data);
// }

// void storeInVector(Node* root, vector<int>&vec){
// 	if(root == NULL) return;
// 	storeInVector(root->left, vec);
// 	vec.push_back(root->data);
// 	storeInVector(root->right, vec);
// }

// void correctBSTUtil(Node* root, vector<int> &vec, int &index){
// 	if(root == NULL) return;
// 	correctBSTUtil(root->left, vec, index);
// 	root->data = vec[index];
// 	index++;
// 	correctBSTUtil(root->right, vec, index);
// }

// void correctBST(Node* root){
	
// 	vector<int> vec;
// 	storeInVector(root, vec);
// 	sort(vec.begin(), vec.end());
// 	int index = 0;
// 	correctBSTUtil(root, vec, index);
// }

// void printInorder(Node* root){
// 	if(root == NULL) return;
// 	printInorder(root->left);
// 	cout<<root->data<<" ";
// 	printInorder(root->right);
// }

// int main(){
	
// 	struct Node *root = newNode(6);
// 	root->left = newNode(10);
// 	root->right = newNode(2);
// 	root->left->left = newNode(1);
// 	root->left->right = newNode(3);
// 	root->right->right = newNode(12);
// 	root->right->left = newNode(7);
	
// 	cout <<"Inorder Traversal of the original tree \n";
// 	printInorder(root);

// 	correctBST(root);
	
// 	cout <<"\nInorder Traversal of the fixed tree \n";
// 	printInorder(root);

// 	return 0;
// }




// Method-2 : Using Recursion


// Two nodes in the BST's swapped, correct the BST.
#include <bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node *left, *right;
};


void swap( int* a, int* b )
{
	int t = *a;
	*a = *b;
	*b = t;
}

struct node* newNode(int data)
{
	struct node* node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void correctBSTUtil( struct node* root, struct node** first,struct node** middle, struct node** last,struct node** prev )
{
	if( root )
	{
		
		correctBSTUtil( root->left, first, middle, last, prev );

		if (*prev && root->data < (*prev)->data)
		{
		
			if ( !*first )
			{
				*first = *prev;
				*middle = root;
			}

			else
				*last = root;
		}

		*prev = root;
		correctBSTUtil( root->right, first, middle, last, prev );
	}
}

void correctBST( struct node* root )
{

	struct node *first, *middle, *last, *prev;
	first = middle = last = prev = NULL;

	correctBSTUtil( root, &first, &middle, &last, &prev );

	if( first && last )
		swap( &(first->data), &(last->data) );
	else if( first && middle ) 
		swap( &(first->data), &(middle->data) );

}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout <<" "<< node->data;
	printInorder(node->right);
}


int main()
{
	
	struct node *root = newNode(6);
	root->left	 = newNode(10);
	root->right	 = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(12);
	root->right->left = newNode(7);

	cout <<"Inorder Traversal of the original tree \n";
	printInorder(root);

	correctBST(root);

	cout <<"\nInorder Traversal of the fixed tree \n";
	printInorder(root);

	return 0;
}

