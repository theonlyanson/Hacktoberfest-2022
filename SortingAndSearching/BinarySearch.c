#include <stdio.h>
#include <stdlib.h>
 
void BinarySearch(int arr[], int key, int first, int last){
 
   if(first > last)
   {
        printf("Number is not found");
 
   }
	else	{
 
        int mid;
 
        
        mid = (first + last)/2;
 
        
        if(arr[mid]==key){
 
            printf("Element is found at index %d ",mid);
            exit(0);
 
        }else if(arr[mid]>key){
 
            
            BinarySearch(arr, key, first, mid-1);
 
        }else{
 
            
            BinarySearch(arr, key, mid+1, last);
        }
 
    }
 
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
 
    
   
   int key;
   	printf("Enter the number to be search:");
	scanf("%d",&key);
 
    int first =0 , last = (sizeof(arr)/sizeof(arr[0]))-1;
 
   BinarySearch(arr, key, first, last);
}
