#include <iostream>
using namespace std;


int main() {
  float *pointer;
  float pay = 3.75;
  pointer = &pay;

  cout << "The value of pointer is: " << pointer << endl;
  cout << "The value of *pointer is: " << *pointer << endl;
  cout << "The value of &pay is: " << &pay << endl;
  cout << "The value of pay is: " << pay << endl;

} 