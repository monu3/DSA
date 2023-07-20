#include <stdio.h>

void insertion_sort(int a[], int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        int next = a[i];
        for (j = i - 1; j >= 0 && a[j] > next; j--)
            a[j + 1] = a[j];
        a[j + 1] = next;
    }
}

int main()
{
    int n, i;
    int arr[100];
    printf("Enter number of elements: \t");
    scanf("%d", &n);
    printf("Enter: \t");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        printf("\t");
    }
    insertion_sort(arr, n);
    printf("\n\n");
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}