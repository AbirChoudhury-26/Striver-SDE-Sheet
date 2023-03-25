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

bool pathValue(node *root,vector<int>&arr,int target)
{
     if(root==NULL)
      return false;

    arr.push_back(root->data);

    if(root->data==target)
     return true;

     if(pathValue(root->left,arr,target)|| pathValue(root->right,arr,target))
      return true;

    arr.pop_back();
     return false;

}

int main()
{
  node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(7);
  root->left->right->right=newNode(9);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(10);

vector<int>arr;
 bool res= pathValue(root,arr,7);

 if(res)
  {
    for(auto it:arr)
     cout<<it<<" ";
  }
 else
  cout<<-1<<" ";
  
  return 0;
}