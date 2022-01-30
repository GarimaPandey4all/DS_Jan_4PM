#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *top = NULL;

struct node *createNode()
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    return n;
};

//insert into a stack
void push()
{
    struct node *temp;

    temp = createNode();

    printf("Enter any value:");
    scanf("%d", &temp->info);

    temp->link = top;

    top = temp;
}

//delete from the stack
void pop()
{
    struct node *t;

    if(top == NULL)
    {
        printf("Stack Underflow");
    }
    else {
        t = top;

        top = top->link;

        free(t);
    }
}

void display()
{
    struct node *t;

    if(top == NULL)
    {
        printf("Stack Underflow");
    }
    else {
        t = top;

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

        printf("\n\nPress 1. Push()\n");
        printf("\nPress 2. Pop()\n");
        printf("\nPress 3. Display()\n");
        printf("\nPress 4. Exit()\n");

        printf("\n\nEnter your choice:\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice");
        }

    }

    return 0;
}
