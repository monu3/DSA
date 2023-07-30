#include <stdio.h>
// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
	// Choosing the pivot
	int pivot = arr[high];
    int temp;

	// Index of smaller element and indicates
	// the right position of pivot found so far
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {

		// If current element is smaller than the pivot
		if (arr[j] < pivot) {

			// Increment index of smaller element
			i++;
			//swap(&arr[i], &arr[j]);
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
		}
	}
	//swap(&arr[i + 1], &arr[high]);
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
	return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
	if (low < high) {

		// pi is partitioning index, arr[p]
		// is now at right place
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Driver code
int main()
{
	// int arr[] = { 10, 7, 8, 9, 1, 5 };
	// int N = sizeof(arr) / sizeof(arr[0]);
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
	// Function call
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}
