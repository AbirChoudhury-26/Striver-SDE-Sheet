#include<iostream>
using namespace std;

typedef struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
} node;

node *root, *temp, *p, *q;

void create_tree()
{

    temp = (node *)malloc(sizeof(node));
    printf("Enter the number:");
    scanf("%d",&temp->data);

    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
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

void preorder(node *);
void inorder(node *);
void postorder(node *);

void search()
{
    int num;
    if (root == NULL)
        printf("No tree exist");
    else
    {
        printf("Enter the number:");
        scanf("%d", &num);
        p = root;
        while (p != NULL)
        {
            if (p->data == num)
            {
                printf("Element Exist\n");
                break;
            }
            else if (p->data > num)
                p = p->left;
            else
                p = p->right;
        }
        if (p == NULL)
            printf("Element Not Found\n");
    }
}

void preorder(node *temp)
{
    if (temp == NULL)
        return;
    printf("%d\n", temp->data);
    preorder(temp->left);
    preorder(temp->right);
    
}

void inorder(node *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    printf("%d \n", temp->data);
    inorder(temp->right);
}

void postorder(node *temp)
{
    if (temp == NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ", temp->data);
}

int main()
{
    int ch;
    while (1)
    {
        printf("Enter the choice:");
        printf("\n1:Insert\n2:Search\n3:Preorder-Traversing\n4:Inorder-Traversing\n5:Postorder-Traversing\n6:Exit\n");
        fflush(stdin);
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_tree();
            break;
        case 2:
            search();
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(0);
        }
    }

    return 0;
}