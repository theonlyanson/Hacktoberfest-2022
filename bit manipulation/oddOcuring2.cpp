//find the two non repeating numbers in an array where every element repeats
using namespace std;
#include <iostream> 
#include <vector>

int find(int arr[],int n){
    int k = 0;
    vector<int> m;
    int s;

    for (int i = 0; i < n; i++)
    {
        k = k^arr[i];
    }
    for (int i = 0; i < n; i++)
    {
         if(arr[i]&1 == 1){               //yaha 1 isliye liya h kyunki jo do integers ka XOR aya usme right end m tha 1 agr kahi aur hota to uska vala number lete
            m.push_back(arr[i]);         // example- agr 00100 hota to uska & 4 se karwate
        } 
    }
           
    for (int i : m)
    {
         s = k^i;
    }
    return s; 
    
}

int main(){
    int arr[] = {5,4,1,4,3,5,1,2}, n = 8;
    cout<<find(arr,n);
}