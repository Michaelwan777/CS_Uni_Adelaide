#include <iostream>
using namespace std;
void factorial (int n);
int main()
{
  int n;
  cout<<"plz enter n"<<endl;
  cin>>n;
  factorial(n);
  return 0;
}
void factorial (int n)
{
  int b=1;
  for(int i=1;i<=n;i++)
    b=b*i;
  cout<<b<<endl;
}
