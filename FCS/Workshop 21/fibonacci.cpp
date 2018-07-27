#include<iostream>
using namespace std;
int Fibonacci(int n);
int main()
{
  int n,i=0;
  cout<<"input n"<<endl;
  cin>>n;
  // for(int i=0;i<n;i++)
  cout<< Fibonacci(i)<<endl;
}
int t=0;
int Fibonacci(int n)
{
  t++;
   cout<<t<<"times"<<endl;
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  return Fibonacci(n-1)+Fibonacci(n-2);

}
