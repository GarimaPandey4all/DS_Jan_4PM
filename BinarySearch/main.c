#include <stdio.h>
#include <stdlib.h>

void binarySearch(int arr[], int first, int last)
{
    int middle;
    int search;

    printf("Enter any value to be search:");
    scanf("%d", &search);

    middle = (first + last)/2;

    while(first <= last)
    {
        if(arr[middle] == search)
        {
            printf("Value is found");
            break;
        }
        else if(arr[middle] < search)
        {
            first = middle + 1;
        }
        else if(arr[middle] > search)
        {
            last = middle - 1;
        }

        middle = (first + last)/2;
    }

    if(first > last)
    {
        printf("Value is not found");
    }
}

int main()
{
    int arr[] = {13, 15, 18, 20, 30, 60, 78};

    binarySearch(arr, 0, 6);

    return 0;
}
