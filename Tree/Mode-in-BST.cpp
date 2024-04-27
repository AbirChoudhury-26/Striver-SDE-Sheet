#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int item)
{
    struct Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with
// given key in BST
struct Node* insert(struct Node* node, int key)
{

    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key >= node->data)
        node->right = insert(node->right, key);

    return node;
}


void inorderTraversal(Node* root, vector<int>& inorder)
{

    if (root == NULL)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}


vector<int> findMode(Node* root)
{
    vector<int> inorder;

    // Find inorder traversal of BST
    inorderTraversal(root, inorder);
    int mx = INT_MIN;
    unordered_map<int, int> mp;

    // Counting occurrences of each
    // element and updating
    // maximum frequency
    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]]++;
        mx = max(mp[inorder[i]], mx);
    }
    vector<int> res;

    for (auto it : mp) {
        if (it.second == mx)
            res.push_back(it.first);
    }
    return res;
}

// Driver's code
int main()
{

    struct Node* root = NULL;
    root = insert(root, 50);

    insert(root, 60);
    insert(root, 50);
    insert(root, 160);
    insert(root, 170);
    insert(root, 140);
    insert(root, 100);


    auto ans = findMode(root);

    cout << "Mode of BST is"
         << " ";
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}