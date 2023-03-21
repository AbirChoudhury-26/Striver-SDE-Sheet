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

vector<int>bottomView(node *root)
{
   vector<int>ans;
    if(root==NULL)
     return ans;
      map<int,int>mp;
      queue<pair<node*,int>>q;
   q.push({root,0});
    
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        node* node= it.first;
        int line= it.second;

        mp[line]=node->data;   // Every time a new value will come in that particular line. Eg:-1,we will get the updated value in map for that line index,which is similar to bootom view of any element & hiding the top elements

        if(node->left!=NULL)
           q.push({node->left,line-1});
        if(node->right!=NULL) 
         q.push({node->right,line+1});
        
    }

     for(auto it:mp)
      ans.push_back(it.second);

return ans;
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

   vector<int>ans= bottomView(root);
    
    for(auto it:ans)
     cout<<it<<" ";
 
}