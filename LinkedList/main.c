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

       // free(t); // delete first node

        printf("Deleted Node is: %d", t->info);
        free(t);
    }
}

void searchList()
{
    struct node *t;
    int search;

    if(start != NULL)
    {
        t = start;

        printf("Enter value to be search:");
        scanf("%d", &search);

        while(t != NULL)
        {
            if(t->info == search)
            {
                printf("%d search value is found", search);
                return;
            }
            t = t->link;
        }

        if(t == NULL)
        {
            printf("%d search value is not found", search);
        }
    }
    else {
        printf("List is Empty. Invalid Search");
    }
}

void viewList()
{
    struct node *t;

    if(start == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = start;

        while(t != NULL)
        {
            printf("%d  ", t->info);
            t = t->link;
        }
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n\nPress 1. Insert\n");
        printf("Press 2. Delete\n");
        printf("Press 3. Search\n");
        printf("Press 4. View\n");
        printf("Press 5. Exit\n");

        printf("\n\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            insertNode();
            break;

        case 2:
            deleteNode();
            break;

        case 3:
            searchList();
            break;

        case 4:
            viewList();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice");
        }
    }


    return 0;
}
