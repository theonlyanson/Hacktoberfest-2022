#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter the size of the array: ";
    int n;cin>>n;
    int arr[n];
    cout<<"Enter the value of K : ";
    int k;cin>>k;
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"The Kth minimum element is : "<<arr[k-1]<<endl;
    cout<<"The Kth maximum element is : "<<arr[n-k];
}