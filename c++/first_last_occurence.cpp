//Program to find index of first and last occurence of an element
#include<iostream>
using namespace std;
//gives the index of first occurence of an element
int first_occ(int arr[],int n,int x)
{
  int low=0;
  int high=n-1;
  while(low<=high)
  {
    int mid=(low+high)/2;
    if(arr[mid]>x)
    {
      high=mid-1;
    }
    else if(arr[mid]<x)
    {
      low=mid+1;
    }
    else
    {
      if(mid==0 || arr[mid-1]!=arr[mid])
      {
        return mid;
      }
      else
      {
        high=mid-1;
      }
    }
  }
  return -1;
}
//gives the index of last occurence of an element
int last_occ(int arr[],int n,int x)
{
  int low=0;
  int high=n-1;
  while(low<=high)
  {
    int mid=(low+high)/2;
    if(arr[mid]>x)
    {
      high=mid-1;
    }
    else if(arr[mid]<x)
    {
      low=mid+1;
    }
    else
    {
      if(mid==n-1 || arr[mid]!=arr[mid+1])
      {
        return mid;
      }
      else
      {
        low=mid+1;
      }
    }
  }
  return -1;
}
//main code
int main()
{
  int arr[]={5,5,10,10,10,10,20,30};
  int n=sizeof(arr)/sizeof(arr[0]);
  int x=10;
  cout<<"First occurence of "<<x<<" is at index: "<<first_occ(arr,n,x)<<endl;
  cout<<"Last occurence of "<<x<<" is at index: "<<last_occ(arr,n,x);
  return 0;
}

