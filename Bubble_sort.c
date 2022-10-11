// BUBBLE SORT USING C PROGRAMME

#include <stdio.h>

void swap(int* xp, int* yp)// function to swap elements
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Implementation of bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
    }
  }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{

    int i, n;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in the array : ");
	for(i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Entered array is : ");
	printArray(arr, n);
	printf("\n");
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
