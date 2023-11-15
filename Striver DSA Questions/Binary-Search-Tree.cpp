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
  cout<<"Enter the number"<<endl;
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

void search()
{
  int num;
  if (root == NULL)
    cout << " Tree doesn't exist";
  else
  {
    cout << "Enter the number"<<endl;
    cin >> num;
    p = root;
    while (p != NULL)
    {
      if (p->data == num)
      {
        cout << "Number exist" << endl;
        break;
      }
      else if (p->data > num)
      {
        p = p->left;
      }
      else
        p = p->right;
    }
    if (p == NULL)
      cout << "Element doesn't exist" << endl;
  }
}



int main()
{
  while (1)
  {
    int ch;
    cout << "Enter the choice:" << endl;
    cout << "\n1:Insert\n2:Search\n3:Exit" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
      create_tree();
      break;
    case 2:
      search();
      break;
    case 3:
     exit(0);
    }
  }

  return 0;
}