using namespace std;
#include <iostream> 

int findodd(int arr[], int n){
    int k;
    for (int i = 0; i < n; i++)
    {
        k = k^arr[i];
    }
    return k;
}

int main(){
    int arr[] = {4,3,4,4,4,5,5};
    int n = 7;
    cout<<findodd(arr, n);
}