#include <iostream>
using namespace std;

int main() {

  int first_number, second_number, sum;
  //Enter 2 numbers one after another
  cout << "Enter two integers: ";
  cin >> first_number >> second_number;

  // sum of two numbers in stored in variable sumOfTwoNumbers
  sum = first_number + second_number;

  // prints the output of sum 
  cout << first_number << " + " <<  second_number << " = " << sum;     

  return 0;
}
