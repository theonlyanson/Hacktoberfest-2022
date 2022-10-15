using namespace std;
#include <iostream> 

void power2(int n){
    int k = 0;
    if(n > 0){
        while(n%2 == 0){
            n = n/2;
            k++;
        }
        if(n == 1){
            cout<<"yes "<<k;
        }
    if(n == 0 || n != 1){
        cout<<"No";
    }
    }
}

int main(){
    power2(8);
}   