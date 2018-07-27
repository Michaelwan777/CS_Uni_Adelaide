#include <iostream>
using namespace std;

int main()
{
  int *a = new int;
  *a = 10;
  int* ptr1_a = a; // does this declaration work? why? if it does not work, please comment it out.
  int** ptr2_a = &a; // how about this declaration? 
  
  cout << "the content of *a is " << *a << endl;
  cout << "the content of a is " << a << endl; // what do you observe in the output? please explain.
  
  cout << "the content of *ptr_a is " << *ptr2_a << endl; // what do you observe in the output? please explain.
  cout << "the content of **ptr_a is " << **ptr2_a << endl; // what do you observe in the output? please explain.
  
  return 0;
}
