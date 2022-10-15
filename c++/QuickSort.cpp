#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int s,int e){
    int pivot = a[e];
    int p = s;
    for(int q=s;q<e;q++){
        if(a[q]<pivot){
            swap(a[p],a[q]);
            p++;
        }
    }
    swap(a[p],a[e]);
    return p;
}


void quicksort(int a[],int s,int e){
    if(s>=e) return;

    int p = partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
