#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct tree
{
  int data;
  struct tree *left, *right;
} node;

node *temp;

node *newNode(int data)
{
  temp = (node *)malloc(sizeof(node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
}

 node* reorder(node *root)
{
  if (root == NULL)
    return 0;
  int child = 0;
  if (root->left)
    child += root->left->data;
  else
    child += root->right->data;

  if (child < root->data)
  {
    if (root->left)
      root->left->data = root->data;
    else if (root->right)
      root->right->data = root->data;
  }

  reorder(root->left);
  reorder(root->right);

  int total = 0;
  if (root->left)
    total += root->left->data;
  else if (root->right)
    total += root->right->data;

  if (root->left || root->right)
    root->data = total;

  return root;
}
void inorderTraversal(node *root, vector<int> &inorder)
{
  if (root == NULL)
    return;
  inorderTraversal(root->left, inorder);
  inorder.push_back(root->data);
  inorderTraversal(root->right, inorder);
}

void changeTree(node *root, vector<int> &inorder)
{
  // cout<<root->data<<endl;
  reorder(root);
  cout<<root->data<<endl;
  inorderTraversal(root, inorder);
}

int main()
{
  node *root = newNode(2);
  root->left = newNode(35);
  root->left->left = newNode(2);
  root->left->right = newNode(3);
  root->right = newNode(10);
  root->right->left = newNode(5);
  root->right->right = newNode(2);

  vector<int> inorder;
  changeTree(root, inorder);

  for (int i = 0; i < inorder.size(); i++)
    cout << inorder[i] << " ";
  cout << endl;
  return 0;
}