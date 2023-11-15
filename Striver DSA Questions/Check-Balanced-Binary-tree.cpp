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
// bool isBalanced(node *root)
// {
//   return balancedTree(root)!= 1;
// }

int  balancedTree(node *root)
{
  if (root == NULL)
    return 0;
  int lh = balancedTree(root->left);
  if (lh == -1)
    return -1;
  int rh = balancedTree(root->right);
  if (rh == -1)
    return -1;

  if (abs(lh - rh) <= 1)
    return 1 + max(lh, rh);
  else
    return -1;
}

int main()
{
  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(8);
  root->left->right->right = newNode(9);
  // root->left->right->left->left = newNode(10);
  // root->left->right->left->right = newNode(11);

  root->right->left = newNode(6);
  root->right->right = newNode(7);

int ans = balancedTree(root);
  if(ans!=-1)
   cout<<"Balanced Tree"<<endl;
  else
   cout<<"Not a Balanced Tree"<<endl;
  return 0;
}