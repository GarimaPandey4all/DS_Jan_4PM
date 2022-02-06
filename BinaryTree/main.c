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

int main()
{
    struct node *root = NULL;

    root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(9);
    root->left->left = createNode(5);
    root->left->right = createNode(6);
    root->right->left = createNode(3);
    root->right->right = createNode(7);

    printf("\nPreOrder Traversal\n");
    preOrder(root);

    printf("\nInOrder Traversal\n");
    inOrder(root);

    printf("\nPostOrder Traversal\n");
    postOrder(root);

    return 0;
}
