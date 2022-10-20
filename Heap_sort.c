#include <stdio.h>
 
void swap(int* a, int* b)
{
 
    int temp = *a;
 
    *a = *b;
 
    *b = temp;
}
 

void heap(int arr[], int size, int i)
{
   
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
     if (left < size && arr[left] > arr[largest])
 
        largest = left;
 
    
    if (right < size && arr[right] > arr[largest])
 
        largest = right;
 
    
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
       
        heap(arr, size, largest);
    }
}
 

void heapSort(int arr[], int size)
{
	
	for (int i = size / 2 - 1; i >= 0; i--)
 
        heap(arr, size, i);
 
    
    for (int i = size - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        
        heap(arr, i, 0);
    }
}
 

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
   int size;
	printf("Enter the Size:");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the Array:");
	int i;
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
 
    
    heapSort(arr, size);
    printf("Sorted array is\n");
    printArray(arr, size);
}
	
