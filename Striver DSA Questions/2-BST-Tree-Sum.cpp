#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorderTraversal(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

int countPairs(Node *root1, Node *root2, int x)
{

    if (root1 == NULL || root2 == NULL)
        return 0;

    vector<int> v1, v2;
    inorderTraversal(root1, v1);
    inorderTraversal(root2, v2);

    int i = 0, j = v2.size() - 1, ans = 0;

    while (i < v1.size() && j >= 0)
    {
        int sum = v1[i] + v2[j];

        if (sum == x)
        {
            ans++;
            i++;
            j--;
        }
        else if (sum < x)
        i++;
        else if(sum>x)
         j--;
    }
}
int main()
{
    return 0;
}