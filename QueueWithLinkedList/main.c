#include <stdio.h>
#include <stdlib.h>

struct queue {
    int info;
    struct queue *link;
};

struct queue *front = NULL;
struct queue *rear = NULL;

struct queue *createQueue()
{
    struct node *n;

    n = (struct queue *)malloc(sizeof(struct queue));

    return n;
};

void enqueue()
{
    struct queue *temp;

    temp = createQueue();

    printf("Enter any number:");
    scanf("%d", &temp->info);

    temp->link = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else {
        rear->link = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct queue *t;

    if(front == NULL)
    {
        printf("Queue is Empty");
    }
    else {
        t = front;

        front = front->link;

        printf("Deleted value is: %d", t->info);

        free(t);
    }
}

void display()
{
    struct queue *t;

    if(front == NULL)
    {
        printf("Queue is Empty");
    }
    else {
        t = front;

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

        printf("\n\nPress 1. Enqueue()\n");
        printf("\nPress 2. Dequeue()\n");
        printf("\nPress 3. Display()\n");
        printf("\nPress 4. Exit()\n");

        printf("\n\nEnter your choice:\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
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
