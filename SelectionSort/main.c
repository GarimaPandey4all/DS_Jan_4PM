#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n)
{
    int i, j, temp, min;

    for(i = 0; i < n - 1; i++)
    {
        min = i; // 0
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;// 1
            }
        }

        //swapping
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};

    selectionSort(arr, 5);

    return 0;
}
