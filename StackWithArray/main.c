#include <stdio.h>
#include <stdlib.h>
#define max 5

//Stack: LIFO: Last in first out
//
//top/peek pointer is used to point the current location of the stack

int i, top = -1, stack[max];

//insert into a stack
void push()
{
    int value;

    if(top == max - 1)
    {
        printf("Stack Overflow");
    }
    else {
        printf("Enter any value:");
        scanf("%d", &value);

        top++;
        stack[top] = value;
    }
}

//delete from the stack
void pop()
{
    int value;

    if(top == -1)
    {
        printf("Stack Underflow");
    }
    else {
        value = stack[top];

        printf("The Deleted Value is: %d\n", value);

        top--;
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack Underflow");
    }

    else {
        printf("The value of the stack are:\n");
        for(int i = top; i >= 0; i--)
        {
            printf("%d  ", stack[i]);
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
