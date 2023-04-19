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

void ceil()
{
    int num;
    cout << "Enter the Number for ceil to found:" << endl;
    cin >> num;
    p = root;
    int ceil=-1;
    while (p != NULL)
    {
        if (p->data == num)
        {
            ceil=p->data;
            break;
        }
        if (p->data < num)
         p=p->right;
        else
        {
          ceil=p->data;
          p=p->left;
        }
    }
     cout<<ceil<<endl;
}

int main()
{
    while (1)
    {
        int ch;
        cout << "\n1:Insert\n2:Ceil\n3:Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            create_tree();
            break;
        case 2:
            ceil();
            break;
        case 3:
         exit(0);
        }
    }


    return 0;
}