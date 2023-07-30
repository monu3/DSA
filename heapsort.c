// Heap Sort in C

#include <stdio.h>
// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
	// Find largest among root,
	// left child and right child

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int left = 2 * i + 1;

	// right = 2*i + 2
	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < N && arr[left] > arr[largest])

		largest = left;

	// If right child is larger than largest
	// so far
	if (right < N && arr[right] > arr[largest])

		largest = right;

	// Swap and continue heapifying
	// if root is not largest
	// If largest is not root
	if (largest != i) {

		//swap(&arr[i], &arr[largest]);
        int temp =  arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build max heap
	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {

		//swap(&arr[0], &arr[i]);
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

		// Heapify root element
		// to get highest element at
		// root again
		heapify(arr, i, 0);
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
    heapSort(arr, n);
    printf("\n\n");
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

