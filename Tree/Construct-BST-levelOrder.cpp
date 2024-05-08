// Approach 1 : Using Recurssion

/* Steps:

First, pick the first element of the array and make it root.
Pick the second element, if its value is smaller than the root node value make it left child,
Else make it right child
Now recursively call step (2) and step (3) to make a BST from its level Order Traversal.

*/

// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
// 	int data;
// 	Node *left, *right;
// };

// Node* getNode(int data)
// {

// 	Node* newNode = (Node*)malloc(sizeof(Node));

// 	newNode->data = data;
// 	newNode->left = newNode->right = NULL;
// 	return newNode;
// }

// Node* LevelOrder(Node* root, int data)
// {
// 	if (root == NULL) {
// 		root = getNode(data);
// 		return root;
// 	}
// 	if (data <= root->data)
// 		root->left = LevelOrder(root->left, data);
// 	else
// 		root->right = LevelOrder(root->right, data);
// 	return root;
// }

// Node* constructBst(int arr[], int n)
// {
// 	if (n == 0)
// 		return NULL;
// 	Node* root = NULL;

// 	for (int i = 0; i < n; i++)
// 		root = LevelOrder(root, arr[i]);

// 	return root;
// }

// void inorderTraversal(Node* root)
// {
// 	if (!root)
// 		return;

// 	inorderTraversal(root->left);
// 	cout << root->data << " ";
// 	inorderTraversal(root->right);
// }

// int main()
// {
// 	int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	Node* root = constructBst(arr, n);

// 	cout << "Inorder Traversal: ";
// 	inorderTraversal(root);
// 	return 0;
// }




// Approach 2: Using Queue


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};


Node *constructBst(int arr[], int n)
{
    // Create queue to store the tree nodes
    queue<pair<Node *, pair<int, int>>> q;

    // If array is empty we return NULL
    if (n == 0)
        return NULL;

    // Create root node and store a copy of it in head
    Node *root = new Node(arr[0]), *head = root;

    // Push the root node and the initial range
    q.push({root, {INT_MIN, INT_MAX}});

    // Loop over the contents of arr to process all the
    // elements
    for (int i = 1; i < n; i++)
    {

        // Get the node and the range at the front of the
        // queue
        Node *temp = q.front().first;
        pair<int, int> range = q.front().second;

        // Check if arr[i] can be a child of the temp node
        if (arr[i] > range.first && arr[i] < range.second)
        {

            // Check if arr[i] can be left child
            if (arr[i] < temp->data)
            {

                if (temp->left != NULL)
                {
                    // if temp already has a left child
                    // temp can have no more children
                    q.pop();
                    i--;
                    continue;
                }

                // Set the left child and range
                temp->left = new Node(arr[i]);
                q.push({temp->left, {range.first, temp->data}});
            }
            
            else
            {

                q.pop();
                temp->right = new Node(arr[i]);
                q.push({temp->right, {temp->data, range.second}});
            }
        }
        else
        {

            q.pop();
            i--;
        }
    }
    return head;
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = constructBst(arr, n);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}
