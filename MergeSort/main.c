#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int n)
{
    int temp[n];
    int size, l1, l2, h1, h2, k, i, j;

    for(size = 1; size < n; size = size * 2)
    {
        l1 = 0;
        k = 0;

        while(l1 + size < n)
        {
            h1 = l1 + size - 1; // 0, 2
            l2 = h1 + 1; // 1, 3
            h2 = l2 + size - 1; // 1, 3 // 15

            if(h2 >= n)
            {
                h2 = n - 1; // 8
            }

            //merge two pairs

            i = l1;
            j = l2;

//            temp:
//            11, 22,

            while(i <= h1 && j <= h2)
            {
                if(arr[i] <= arr[j])
                {
                    temp[k++] = arr[i++];
                }
                else {
                    temp[k++] = arr[j++];
                }
            }

            while(i <= h1)
            {
                temp[k++] = arr[i++];
            }

            while(j <= h2)
            {
                temp[k++] = arr[j++];
            }

            //merge completed

            l1 = h2 + 1; // 2
        }

        //any pair left
        for(i = l1; i < n; i++)
        {
            temp[k++] = arr[i];
        }

        for(i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }

        printf("\nSize of %d elements are:\n", size);
        for(i = 0; i < n; i++)
        {
            printf("%d  ", arr[i]);
        }
    }
}

int main()
{
    int arr[] = {11, 22, 44, 33, 11, 66, 55, 88, 77};
    int i;

    mergeSort(arr, 9);

    return 0;
}
