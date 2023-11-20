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
    cout << "Enter the number" << endl;
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

bool searchBST(node *root, int x)
{
    if(root==NULL)
     return false;
    
    if(root->data==x)
     return true;
    
    if(root->data>x)
     return searchBST(root->left,x);
    else
     return searchBST(root->right,x);
}

int main()
{
    int x;
    cin >> x;
    while (1)
    {
        int ch;
        cout << "Enter the choice:" << endl;
        cout << "\n1:Insertn\n2:Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            create_tree();
            break;
        case 2:
            exit(0);
        }
    }

    bool ans=searchBST(root,x);
     if(ans==true)
      cout<<"True"<<endl;
    else
     cout<<"False"<<endl;

    return 0;
}