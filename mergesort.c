#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, b[100];
    while ( i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            ++i, ++k;
        }
        if (arr[j] < arr[i])
        {
            b[k] = arr[j];
            ++j, ++k;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        ++i, ++k;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        ++k, ++j;
    }
    for(int i = low; i <= high; i++) arr[i] = b[i];
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    mergesort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}