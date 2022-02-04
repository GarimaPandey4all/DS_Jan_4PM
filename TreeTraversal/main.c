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

struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);

    return root->left;
};


struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);

    return root->right;
};

int main()
{
    struct node *root = NULL;

    root = createNode(30);

    insertLeft(root, 20);
    insertRight(root, 39);
    insertLeft(root->left, 10);
    insertRight(root->left, 25);
    insertRight(root->right, 39);
    insertLeft(root->right, 35);
    insertRight(root->right, 42);

    printf("\nPreOrder Traversal\n");
    preOrder(root);

    printf("\nInOrder Traversal\n");
    inOrder(root);

    printf("\nPostOrder Traversal\n");
    postOrder(root);

    return 0;
}
