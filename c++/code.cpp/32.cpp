#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=n;
    while(i>=1){
        int j = i;
       
        while(j<=n){
            char ch ='A'+j-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i--;
    }
}