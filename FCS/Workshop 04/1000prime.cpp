#include<iostream>
using namespace std;
int prime (int a);
int main()
{
  int a;
  cout<<"plz enter a"<<endl;
  cin>>a;
  if( prime(a))
    cout<<"yes, "<<a<<"is a prime number"<<endl;
  else
    cout<<"no, "<<a<<"is not a prime number"<<endl;
  cout<<"*********************************************************"<<endl;
  cout<<"*********************************************************"<<endl;
for (int j=2;j<=1000;j++)
{
	if(prime(j))//true  is
	cout<<j<<"   ";
}
  return 0;
}
int prime (int a)
{
  int b;
  int flag = 1;
  for(int i=2;i<a;i++)
    {
      b=a%i;
      if (b==0)//not
        flag = 0;
    }
  if(flag == 1)
    return 1;// is a prime number
  else
    return 0;// is not a prime number
}


