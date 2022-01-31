#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max], front = -1, rear = -1;

void enqueue()
{
    int value;

    if(rear == max - 1)
    {
        printf("Queue is Full");
    }
    else {
        printf("Enter any value:");
        scanf("%d", &value);

        if(front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue is Empty");
    }

    else {
        printf("Deleted value is: %d", queue[front]);
        front++;

        if(front > rear)
        {
            front = rear = - 1;
        }
    }
}

void display()
{
    if(rear == -1)
    {
        printf("Queue is Empty");
    }

    else {
        int i;

        printf("Elements in queue are:\n");
        for(i = front; i <= rear; i++)
        {
            printf("%d  ", queue[i]);
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
