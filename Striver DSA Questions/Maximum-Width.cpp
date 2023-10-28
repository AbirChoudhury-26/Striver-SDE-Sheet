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

int widthBinaryTree(node *root)
{
    if (!root)
        return 0;
    int ans = 0;

    queue<pair<node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        int currMin = q.front().second;
        int leftmost, rightmost;
        for (int i = 0; i < size; i++)
        {
            int curr_val = q.front().second - currMin;
            node *temp = q.front().first;
            q.pop();

            if (i == 0)
                leftmost = curr_val;
            if (i == size - 1)
                rightmost = curr_val;

            if (temp->left)
                q.push({temp->left, (2 * curr_val + 1)});

            if (temp->right)
                q.push({temp->right, (2 * curr_val + 2)});
        }
        ans = max(ans, rightmost - leftmost+1);
     
    }
       return ans;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(9);
    root->right->left = newNode(6);
    root->right->right = newNode(10);

    int maxWidth = widthBinaryTree(root);
    cout<<maxWidth<<endl;
    return 0;
}