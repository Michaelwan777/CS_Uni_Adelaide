#include<iostream>
#include "student.h"
using namespace std;
int main()
{ 
  student stu1;
  stu1.set_name("zhao","yan");
  stu1.set_address(67,"arthurstreet","tranmere","adl","au",5073);
  stu1.set_CR("FCS",100);
  stu1.set_age(18);
  stu1.show();
  cout<<"age is  "<< stu1.get_age()<<endl;
  // cout<<stu1.get_name();
  return 0;
}
