#include<iostream>
using namespace std;
void raise_to_power (float a,int b);
int main()
{
  float a;
  int b;
  raise_to_power(a,b);
  return 0;
}
void raise_to_power (float a,int b)
{
  float c=1.0;
  cout<<"plz enter number a and the integer power b"<<endl;
  cin>>a>>b;
  if(b>0)
    {
      while(b>=1)
    {
      c=c*a;
      b--;
    }
       cout<<c<<endl;
    }
   else if (b<0)
       { cout<<"error"<<endl;}
   else
      { cout<<c<<endl;}
}
