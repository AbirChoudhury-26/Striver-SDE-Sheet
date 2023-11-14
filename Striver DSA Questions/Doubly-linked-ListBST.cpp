#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Tree creation

typedef struct tree{
    int data;
    struct tree *left,*right;

}treenode;

treenode *temp;

treenode *newNode(int data)
{
  temp=(treenode*)malloc(sizeof(treenode));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
}


// Doubly Linked list creation

typedef struct linknode
{
    struct linknode *prev;
    int data;
    struct linknode *next;

} node;

node *te, *start, *last;

void create_node(int val)
{
    te = (node *)malloc(sizeof(node));
    te->data=val;
    te->next = NULL;
    te->prev = NULL;
     if(start==NULL)
      {
        start=te;
        last=te;
      }
      else{
        last->next=te;
        te->prev=last;
        last=last->next;
      }
}

void inorder(treenode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    create_node(root->data);
    inorder(root->right);
}

void display()
{
    if(start==NULL)
     cout<<"No Elements are present"<<endl;
    else{
        node *p;
        p=start;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=NULL);
    }
}
 
int main()
{
   treenode * root = newNode(4);
  root -> left = newNode(2);
  root -> right = newNode(5);
  root -> left -> left = newNode(1);
  root -> left -> right = newNode(3);

   inorder(root);

   // Display Doubly Linked List

     display();

  return 0;
}