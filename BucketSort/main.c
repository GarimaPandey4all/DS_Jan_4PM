#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n)
{
    int i, j;

    int count[n+1];

    for(i = 0; i <= n; i++)
    {
        count[i] = 0;
    }

    for(i = 0; i <= n; i++)
    {
        count[arr[i]]++; // + 1
    }

    for(i = 0, j = 0; i < n; i++)
    {
        while(count[i] > 0)
        {
            arr[j++] = i; // 1
            count[i]--;// 2 - 1 = 1
        }
    }
}


int main()
{
    int arr[] = {5, 2, 1, 4, 3, 1};
    int i;

    bucketSort(arr, 6);

    printf("Sorted Array:\n");
    for(i = 0; i <= 5; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
