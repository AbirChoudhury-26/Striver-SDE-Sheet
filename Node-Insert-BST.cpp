#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct tree
{
    int data;
    struct tree *left, *right;
} node;

node *root, *temp, *p, *q;

void create_tree()
{

    temp = (node *)malloc(sizeof(node));
    cout << "Enter the number: ";
    cin >> temp->data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        root = temp;
    else
    {
        p = root;
        while (p != NULL)
        {
            if (temp->data < p->data)
            {
                q = p;
                p = p->left;
            }
            else
            {
                q = p;
                p = p->right;
            }
        }
        if (q->data > temp->data)
            q->left = temp;
        else
            q->right = temp;
    }
}

void inorder(node *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

node*  insertIntoBST(node* root,int val)
{
 if(root==NULL)
  return;
  node *cur=root;
  while(true)
  {
    if(cur->data <=val)
    {
         if(cur->right!=NULL)
          cur=cur->right;
          else
          {
            cur->right=


          }
    }
  }
}

int main()
{
    while (1)
    {
        int ch,val;
        cout << endl<< "Enter the choice:" << endl;
        cout << "\n1:Insert\n2:Inorder Traversal\n3:Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            create_tree();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
           cin>>val;
          insertIntoBST(root,val);
        case 4:
            exit(0);
        }
    }

    return 0;
}