//Programm to search index of an element in sorted rotated array
#include<iostream>
using namespace std;
int search(int arr[],int n,int x)
{
  int low=0,high=n-1;
  while(low<=high)
  {
    int mid=(low+high)/2;
    if(arr[mid]==x)
    {
      return mid;
    }
    if(arr[low]<arr[mid])   //for left half
    {
      if(x>=arr[low] && x<arr[mid])
      {
        high=mid-1;
      }
      else
      {
        low=mid+1;
      }
    }
    else                 //for right half
    {
      if(x>arr[mid] && x<=arr[high])
      {
        low=mid+1;
      }
      else
      {
        high=mid-1;
      }
    }
  }
  return -1;   //element not exist

}
int main()
{
  int arr[]={10,20,40,60,5,8};
  int n=sizeof(arr)/sizeof(arr[0]);
  int x=5;
  cout<<"Element "<<x<< " is present at index: "<<search(arr,n,x);
  return 0;
}