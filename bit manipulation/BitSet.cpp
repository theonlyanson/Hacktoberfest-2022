using namespace std;
#include <iostream> 

void bit(int n){
    int k;
    while(n != 0){
        n = n & (n-1);
        k++;
    }
    cout<<k;
}

int main(){
    bit(7);
}