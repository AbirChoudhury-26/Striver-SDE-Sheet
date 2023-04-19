#include<iostream>
#include<bits/stdc++.h>
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
  cout<<"Enter the number: "<<endl;
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

void floor()
{
    int num;
    cout << "Enter the Number for floor to found:" << endl;
    cin >> num;
    p = root;
    int floor=-1;
    while (p != NULL)
    {
        if (p->data == num)
        {
            floor=p->data;
            break;
        }
        if (p->data > num)
         p=p->left;
        else
        {
          floor=p->data;
          p=p->right;
        }
    }
     cout<<floor<<endl;
}

int main()
{
  
  while (1)
    {
        int ch;
        cout << "\n1:Insert\n2:Floor\n3:Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            create_tree();
            break;
        case 2:
            floor();
            break;
        case 3:
         exit(0);
        }
    }

  return 0;
}