#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *start = NULL;

struct node *createNode()
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    return n;
};

void insertNode()
{
    struct node *temp, *t;

    temp = createNode();

    printf("Enter any value:");
    scanf("%d", &temp->info);

    temp->link = NULL;

    if(start == NULL) // list is empty
    {
        start = temp;
    }
    else { // list is not empty
        t = start;

        while(t->link != NULL)
        {
            t = t->link;
        }

        t->link = temp;
    }

}

void deleteNode()
{
    struct node *t;

    if(start == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = start;

        start = start->link;

        free(t); // delete first node
    }
}

int main()
{


    return 0;
}
