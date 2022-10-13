#include <iostream>
using namespace std;
  
// Insertion sorting algorithm for arrays
void insertionSort(int arr[], int n) 
{
    // Step through the array starting at the second element
    int i, key, j; 
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // Element to be inserted
        j = i - 1; // iterator for sorted portion of array
  
        // Insert elem into the correct position within
        // the sorted portion of the array
        while (j >= 0 && arr[j] > key)
        { 
            // Shift elem down an index
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key;  // insert elem in correct index
    } 
} 
  
// Print out the contents of an array
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
} 
  
// Main driver. Testing insertion sort algorithm
int main() 
{ 
    int arr[] = { 10, 5, 6, 1, 7, 3, 2, 9, 4, 8 }; 
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n); 
    cout << "Sorted array: " << endl;
    printArray(arr, n);
  
    return 0; 
} 
