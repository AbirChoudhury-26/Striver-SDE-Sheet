#include<iostream>
#include<bits/stdc++.h>
using namespace std;


typedef struct tree {
    int data;
    struct tree *left,*right;
}node;
 node *temp;

node *newNode(int data)
{
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
}


void leftReccursion(node *root,int level,vector<int>&res)
{
   if(root==NULL)
    return ;
   if(res.size()==level)
    res.push_back(root->data);
leftReccursion(root->left,level+1,res);
leftReccursion(root->right,level+1,res);
}


vector<int>leftSideView(node *root)
{
  vector<int>res;
   leftReccursion(root,0,res);
    return res;
}

 int main()
 {
    node * root = newNode(10);
  root -> left = newNode(20);
  root -> right = newNode(30);
  root -> left -> left = newNode(40);
  root -> left -> right = newNode(60);
//   root -> left -> right -> left = newNode(8);
//   root -> right -> left = newNode(6);
//   root -> right -> right = newNode(7);
//   root -> right -> right -> left = newNode(9);
//   root -> right -> right -> right = newNode(10);

    vector<int>ans=leftSideView(root);
     for(auto it:ans)
      cout<<it<<" ";
    
 }