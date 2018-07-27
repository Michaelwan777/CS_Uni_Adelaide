#include<iostream>
using namespace std;
int main()
{
  int a,*p;
  a=42;
  p=&a;
  *p=*p+5;
  cout<<*p<<endl;
  *p=*p-2;
  cout<<*p<<endl;
}

