using namespace std;
#include <iostream>

// void kbit(int a, int b){
//     if(a&(1<<(b-1)) != 0){
//         cout<<"Yes";
//     } else {
//         cout<<"No";
//     }
// }
void kbit(int a, int b){
    if(((a>>(b-1))&1) != 0){
        cout<<"Yes";
    } else {
        cout<<"No";
    }
}

int main(){
    kbit(5,2);
}