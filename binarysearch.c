// Binary Search in C

#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}


//for sorting 
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

int main(void) {
   int n, i,x;
    int array[100];
    printf("Enter number of elements: \t");
    scanf("%d", &n);
    printf("Enter: \t");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        printf("\t");
    }
    insertion_sort(array, n);
    printf("\n\n");
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    printf("Enter the search element in array: ");
    scanf("%d",&x);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}