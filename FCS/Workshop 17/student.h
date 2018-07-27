#ifndef _STUDENT_H_   // if x.h hasn't been included yet...
#define _STUDENT_H_   //   #define this so the compiler knows it has been included
#include<string>
using namespace std;
struct name
{
  string  firstname;
  string secondname;
};
struct address
{
  int Streetnumber;
  string  StreetName;
  string Suburb;
  string City;
  string  State;
  int  postcode;
};
struct CR
{
  string coursename;
  int score;
};
class student
{
   name name1;
  address address1;
  int age;
  CR CR1;
public:
  student()
  {}
  void set_name(string name,string name2);
  void set_address(int a,string b, string c,string d,string e, int );
  void set_CR(string a, int b);
  void set_age(int a);
  //  name get_name();
  //  void get_address();
  //  void get_CR();
  void show();
  int get_age();
};


#endif
