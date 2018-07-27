#include<iostream>
using namespace std;
void is_positive (int i);
int main()
{
  int i;
  cout<<"enter the integer"<<endl;
  cin>>i;
  is_positive(i);
  return 0;
}
void is_positive (int i)
{
  if (i<0)
    cout<<i<<"  is negetive"<<endl;
  else if(i==0)
    cout<<i<<" is equal to 0"<<endl;
  else
    cout<<i<<" is positive"<<endl;
}
