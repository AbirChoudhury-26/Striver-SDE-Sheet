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

bool isSymmetrical(node* root1,node*root2)
{
  if(root1==NULL || root2==NULL)
   return root1==root2;

return(root1->data ==root2->data && isSymmetrical(root1->left,root2->right) && isSymmetrical(root1->right,root2->left));
 
}

bool treeSymmetrical(node* root)
{
    if(!root) return true;
    return  isSymmetrical(root->left,root->right);

}

int main()
{
   node *root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> right = newNode(4);
  root -> right = newNode(2);
  root -> right -> left = newNode(4);
  root -> right -> right = newNode(3);

  bool res=treeSymmetrical(root);
   if(res)
    cout<<"Tree is symmetrical"<<endl;
   else
    cout<<"Tree is Not Symmetrical"<<endl;

  return 0;
}