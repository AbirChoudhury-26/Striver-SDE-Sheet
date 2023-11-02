#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 typedef struct tree{
    int data;
     struct tree *left,*right;
}node;

node *temp;

node *newNode(int data)
{
  temp=(node*)malloc(sizeof(node));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
}

int heightTree(node *root)
{
   if(root==NULL)
    return 0;

    int lh=heightTree(root->left);
    int rh=heightTree(root->right);
     
      return 1+max(lh,rh);
}


int main()
{
    node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root->left->right->right=newNode(9);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);

  int ans=heightTree(root);
  cout<<ans<<endl;
  return 0;
}