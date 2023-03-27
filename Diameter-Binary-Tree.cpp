#include<iostream>
#include<bits/stdc++.h>
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

int diameterTree(node *root,int &diameter)
{
  if(!root)
   return 0;
 
 int lh=diameterTree(root->left,diameter);
 int rh=diameterTree(root->right,diameter);
 cout<<root->data<<" "<<lh<<" "<<rh<<" "<<diameter<<endl;

   diameter = max(diameter,lh+rh);

   return 1 + max(lh,rh);

return diameter;
}

int main()
{
   node *root = newNode(4);
  root->left = newNode(7);
  root->right = newNode(8);
//   root->left->left = newNode(4);
//   root->left->right = newNode(5);
//   root->left->right->left = newNode(8);
//   root->left->right->right = newNode(9);
  // root->left->right->left->left = newNode(10);
  // root->left->right->left->right = newNode(11);

  root->right->left = newNode(1);
  root->right->left->left=newNode(3);
  root->right->left->left->left=newNode(5);

   root->right->right = newNode(0);
   root->right->right->right=newNode(11);
   root->right->right->left=newNode(2);
   root->right->right->left->left=newNode(0);

   int diameter=0;
  int ans=diameterTree(root,diameter);
  cout<<ans<<endl;
  return 0;
}