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

int findmaxPath(node* root,int &maxi)
{
if(root==NULL)
   return 0;
int lh=max(0,findmaxPath(root->left,maxi));
int rh=max(0,findmaxPath(root->right,maxi));
int val=root->data;
maxi=max(maxi,lh+rh+val);
 return max(lh,rh)+val;
}

int maxSumTree(node* root)
{
  
 int maxi=INT_MIN;
  findmaxPath(root,maxi);
   return maxi;

}

int main()
{
  node * root = newNode(-10);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);

   int ans=maxSumTree(root);
   cout<<"Max-Path sum is: "<<ans<<endl;
  return 0;
}