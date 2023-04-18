#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct node{
	int data;
	node *left,*right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

node* insertBST(node *root,int val)
{
	if(root==NULL)
	{
		return new node(val);
	}
	if(val<root->data)
	{
		root->left=insertBST(root->left,val);
	}
	else
	{
		root->right=insertBST(root->right,val);
	}
	return root;
}

node* klargest(node *root,int &k)
{
  if(root==NULL)
   return NULL;

   node *right=klargest(root->right,k);
    if(right!=NULL) 
     return right;
    k--;

    if(k==0)
     return root;
    
    return klargest(root->left,k);
}

node* kthsmallest(node* root,int &k)
{
	if(root==NULL)
	return NULL;
	
	node* left=kthsmallest(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	if(k==0)
	return root;
	
	return kthsmallest(root->right,k);
}


int main()
{
  int arr[]={10,20,30,45,25,30,50};
 int k;
 cin>>k;
  node *root=NULL;

  for(int i=0;i<7;i++)
  {
    root=insertBST(root,arr[i]);
  }

  cout<<endl;

  int p=k;
   node *large=klargest(root,k);
     k=p;
	node* small=kthsmallest(root,k);
	if(large==NULL)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	cout<<"kth largest element is  "<<large->data<<"\n";
	
	if(small==NULL)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	{
		cout<<"kth smallest element is  "<<small->data<<"\n";
	}
  return 0;
}