#include<bits/stdc++.h>
using namespace std;

void heapsort(int a[],int n){
    for(int i=1;i<n;i++){
        int ci = i;
        while(ci>0){
            int pi = (ci-1)/2;
            if(a[pi]>a[ci]){
                swap(a[pi],a[ci]);
                ci = pi;
            }
            else break;
        }
    }

    int size = n;
    while(size>=1){
        int pi = 0;
        swap(a[0],a[size-1]);
        size--;
        while(true){
            int lci = 2*pi+1;
            int rci = 2*pi+2;
            int minindex = pi;
            if(lci<size && a[minindex]>a[lci]){
                minindex = lci;
            }
            if(rci<size && a[minindex]>a[rci]){
                minindex = rci;
            }
            if(pi==minindex) break;
            swap(a[pi],a[minindex]);
            pi = minindex;
        }
    }
}


int main(){
    int a[] = {23,31,2,12,43,5,1,78};
    heapsort(a,8);
    for(auto x:a){
        cout<<x<<" ";
    }
}
