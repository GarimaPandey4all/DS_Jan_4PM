#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int first, int last)
{
    int pivot, i, j, temp;

    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i < j)
        {
            while(arr[pivot] >= arr[i])
            {
                i++;
            }

            while(arr[pivot] < arr[j])
            {
                j--;
            }

            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        //pivot and j swap
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        //left sub -array
        quickSort(arr, 0, j - 1);

        //right sub - array
        quickSort(arr, j + 1, last);
    }
}

int main()
{
    int arr[] = {35, 50, 15, 25, 80, 20, 90, 45};

    quickSort(arr, 0, 7);

    printf("QuickSorted Array is:\n");
    for(int i = 0; i < 8; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
