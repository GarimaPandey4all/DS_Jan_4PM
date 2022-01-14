#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int n)
{
    int i, j, temp;

    int m = n / 2;

    while(m > 0)
    {
        for(i = m; i < n; i++)
        {
            for(j = i - m; j >= 0; j = j - m)
            {
                if(arr[j] > arr[j + m])
                {
                    temp = arr[j];
                    arr[j] = arr[j + m];
                    arr[j + m] = temp;
                }
                else {
                    break;
                }
            }
        }

        m = m / 2;
    }

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{
    int arr[] = {2, 8, 4, 3, 10};

    shellSort(arr, 5);

    return 0;
}
