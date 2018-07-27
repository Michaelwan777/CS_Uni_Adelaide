#ifndef _STUDENT_H_   // if x.h hasn't been included yet...
#define _STUDENT_H_   //   #define this so the compiler knows it has been included
class student
{
  struct name;
  struct address;
  int age;
  struct CR;
public:
  student()
  {}
  void set_name(string name,string name2);
  void set_address();
  void setCR();
  name get_name();
  void get_address();
  void get_CR();
};

struct name
{
  string  firstname;
  string secondname;
};
name namefs;
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
#endif
