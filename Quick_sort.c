#include <stdio.h>

/* function that consider last element as pivot,
place the pivot at its exact position, and place
smaller elements to left of pivot and greater
elements to right of pivot.  */

int partition (int arr[], int start, int end)
{
    int pivot = arr[end]; // pivot element
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = t;
    return (i + 1);
}

/* Function to implement quick sort */
void quick(int arr[], int start, int end) /* arr[] = array to be sorted, start = Starting index, end = Ending index */
{
    if (start < end)
    {
        int p = partition(arr, start, end); //p is the partitioning index
        quick(arr, start, p - 1);
        quick(arr, p + 1, end);
    }
}

/* function to print an array */
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
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
    quick(arr, 0, n - 1);
    printf("Sorted array : ");
    printArray(arr, n);
    return 0;
}
