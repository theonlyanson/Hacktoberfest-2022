// Author : pk
// H pattern
/*
#                    #
 ##                ##
  ###            ###
   ####        ####
    #####    #####
     ############
     ############
    #####    #####
   ####        ####
  ###            ###
 ##                ##
#                    #
*/
#include<iostream>
using namespace std;
int main(){
	int n,i,a,b,c,x;
	cin >> n;
	for(i=1;i<=n;i++){
		for(a=1;a<=i-1;a++) cout << " ";
		for(b=1;b<=i;b++) cout << "#";
		int x= (4*n-2)-(2*(a+b-2));
		for(c=1;c<=x;c++) cout << " ";
		for(b=1;b<=i;b++) cout << "#";
		cout << endl;
	}
	for(i=n;i>=1;i--){
		for(a=1;a<=i-1;a++) cout << " ";
		for(b=1;b<=i;b++) cout << "#";
		int x= (4*n-2)-(4*i-2);
		for(c=1;c<=x;c++) cout << " ";
		for(b=1;b<=i;b++) cout << "#";
		cout << endl;
	}
	return 0;
}
