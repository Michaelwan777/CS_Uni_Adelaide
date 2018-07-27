#include<iostream>
#include<string>
#include"student.h"
using namespace std;
void student:: set_name(string a,string b)
{
 name1.firstname=a;
 name1.secondname=b;
}
void student::set_address(int a,string b, string c,string d,string e, int f)
{
  address1.Streetnumber=a;
  address1.StreetName=b;
  address1.Suburb=c;
  address1.City=d;
  address1.State=e;
  address1.postcode=f;
}
void student::set_CR(string a,int b)
{
  CR1.coursename=a;
  CR1.score=b;
}
void student::set_age(int a)
{
  age=a;
}
int student::get_age()
{
  return age;
}
/*name student::get_name()
{
  return name1;
  }*/
//void student::get_address()
//void student::get_CR()
void student:: show()
{
  cout<<"your name is  "<<name1.firstname<<" "<<name1.secondname<<endl;
  cout<<"streetnumber: "<<address1.Streetnumber<<endl;
  cout<<"suburb: "<<address1.Suburb<<endl;
  cout<<"city: "<<address1.City<<endl;
  cout<<"state: "<<address1.State<<endl;
  cout<<"postcode: "<<address1.postcode<<endl;
  cout<<"coursename is "<<CR1.coursename<<endl;
  cout<<"score is "<<CR1.score<<endl;
}
/*int main()
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
  }*/
