/* C program for Merge Sort */

#include <stdio.h>
#include <stdlib.h>

/* Merges two subarrays of arr[].
   First subarray is arr[l..m]
   Second subarray is arr[m+1..r]
*/
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l ----> left index to be sorted
   r ----> right index to be sorted  */

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* Function to print an array */

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver code */
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
	mergeSort(arr, 0, n - 1);
	printf("Sorted array is :  ");
	printArray(arr, n);
	return 0;
}
