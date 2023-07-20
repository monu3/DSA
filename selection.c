#include <stdio.h>

void select_sort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int n,i;
    int arr[100];
    printf("Enter number of elements: \t");
    scanf("%d", &n);
    printf("Enter: \t");    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        printf("\t");
    }
    select_sort(arr, n);
    printf("\n\n");
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}