#include <iostream>
#include <bits/stdc++.h>
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

bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;

    return ((root1->data == root2->data) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
}

int main()
{

    node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->right->left = newNode(4);
    root1->right->right = newNode(5);

    node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->right->left = newNode(4);

    if (isIdentical(root1, root2))
    cout << "Trees are identical in nature" << endl;
    else cout << "Trees are Not Identical in Nature" << endl;
    return 0;
}