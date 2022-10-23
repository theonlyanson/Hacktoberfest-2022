#include<bits/stdc++.h> 
using namespace std; 

void cycleSortDistinct(int arr[], int n) 
{ 
    for(int cs=0;cs<n-1;cs++){
        int item=arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++)
            if(arr[i]<item)
                pos++;
        swap(item,arr[pos]);
        while(pos!=cs){
            pos=cs;
            for(int i=cs+1;i<n;i++)
                if(arr[i]<item)
                    pos++;
            swap(item,arr[pos]);
        }
    }
} 
  
int main() 
{ 
int n;
	printf("Enter the Size:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the Array:");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
    
    cycleSortDistinct(arr, n); 
   
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
        
    return 0; 
} 
