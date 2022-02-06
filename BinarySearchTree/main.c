#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left;
    struct node *right;
};

struct node *createNode(value)
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    n->info = value;
    n->left = NULL;
    n->right = NULL;

    return n;
};

struct node *insert(struct node *root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->info)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->info)
    {
        root->right = insert(root->right, value);
    }
};

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d  ", root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d  ", root->info);
        inOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d  ", root->info);
    }
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 8);

    insert(root, 10);
    insert(root, 7);
    insert(root, 5);
    insert(root, 17);
    insert(root, 25);
    insert(root, 35);

    printf("\nPreOrder Traversal\n");
    preOrder(root);

    printf("\nInOrder Traversal\n");
    inOrder(root);

    printf("\nPostOrder Traversal\n");
    postOrder(root);

    return 0;
}
