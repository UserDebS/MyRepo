#include <stdio.h>

void swap(int *p, int *q)
{
    if (*p != *q)
    {
        *p += *q;
        *q = *p - *q;
        *p -= *q;
    }
}

int partition(int arr[], int low, int high)
{
    int i = low + 1, pivot = low, j = high;
    do
    {
        while (arr[i] <= arr[pivot])
            ++i;
        while (arr[j] > arr[pivot])
            --j;
        if (i < j)
            swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[pivot], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main()
{
    int arr[] = {8,7,6,5,4,3,2,1};
    quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}