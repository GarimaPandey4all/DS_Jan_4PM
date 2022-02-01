#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max], front = -1, rear = -1;

void enqueue()
{
    int value;

    if((front == rear + 1) || (front == 0 && rear == max -1))
    {
        printf("Queue is full");
    }
    else {
        printf("Enter any value:");
        scanf("%d", &value);

        if(front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % max;

        queue[rear] = value;

        printf("\nInserted value is: %d", value);
    }
}

void dequeue()
{
    int value;

    if(front == -1)
    {
        printf("Queue is Empty");
    }
    else{
        value = queue[front];

        if(front == rear)
        {
            front = rear = -1;
        }
        else {
            front = (front + 1) % max;
        }

        printf("\nDeleted Value is: %d", value);
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is Empty");
    }
    else {
        printf("\nFront is: %d", front);
        printf("\nValue is:");
        int i;
        for( i = front; i != rear; i = (i + 1) % max)
        {
            printf("%d  ", queue[i]);
        }
        printf("%d  ", queue[i]);
        printf("\nRear is: %d", rear);
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
