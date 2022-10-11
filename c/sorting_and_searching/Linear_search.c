//TRAVERSAL : visiting every element of the array;
//INSERTION :  CASE 1 : MAINTAN ORDER WHILE INSERTING  : BEST CASE INSERTION : O(1); WORST CASE : O(n)
//CASE 2 : NO NEED TO MAINTAIN ORDER :
#include<stdio.h>
void display(int arr[], int n){
for(int i = 0;i<n;i++){
        printf("%d ", arr[i]);
    }

}
int insertion_sorted(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        printf("THE ELEMENT CANNOT BE INSERTED AS IT IS OUT OF BOUNDS OF THE ARRAY ");
        return -1;
    }
    else{
            printf("\nINSERSTION SUCCESFULL\n");
            for(int i = size-1;i>=index-1;i--){
                arr[i+1] = arr[i];
            }
            arr[index] = element;
            return 1;
    }

}

int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5;
    display(arr, size);
    insertion_sorted(arr, size, 9,  100, 3 );
    size+=1;
    display(arr, size);
    return  0;
}

