#include<iostream>
using namespace std;
class rec
{
private:

  static int number;
  int n;

public:

int Fibonacci(int n)
{
  number++;
   cout<<number<<"times"<<endl;
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  return Fibonacci(n-1)+Fibonacci(n-2);
}

};
int rec::number=0;
int main()
{
  rec a;
  int n;
  cout<<"input"<<endl;
  cin>>n;
  cout<< a.Fibonacci(n-1);
}
