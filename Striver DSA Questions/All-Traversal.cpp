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
  void alltraversal(node *root,vector<int>&pre,vector<int>&in,vector<int>&post)
  {
        stack<pair<node*,int>>st;
        st.push({root, 1});
         if(root==NULL)
          return;
        
        while(!st.empty())
        {
             auto it=st.top();
             st.pop();
         
                 // Checking for first time in Preorder call
              if(it.second==1)
              {
                pre.push_back(it.first->data);
                it.second++;
                 st.push(it);

                if(it.first->left!=NULL)
                 {
                    st.push({it.first->left,1});
                 }
              }

            else if(it.second==2)
            {
                 in.push_back(it.first->data);
                 it.second++;
                 st.push(it);
                  if(it.first->right!=NULL)
                   {
                  st.push({it.first->right,1});
                   }
            }

            else
             post.push_back(it.first->data);
        }        
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

  vector<int>pre,in,post;

   alltraversal(root,pre,in,post);

cout<<"Preorder Traversal is: ";
    for(auto it:pre)
     cout<<it<<" ";
cout<<endl;
cout<<"Inorder Traversal is: ";
     for(auto it1:in)
     cout<<it1<<" ";
cout<<endl;
cout<<"Postorder Traversal is: ";
     for(auto it2:post)
     cout<<it2<<" ";

}