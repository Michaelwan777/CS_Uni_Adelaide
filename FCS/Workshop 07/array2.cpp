#include<iostream>
using namespace std;
void reserve(int j);
int main()
{
  int j;
  cout<<"how many numbers do you want to input"<<endl;
  cin>>j;
  cout<<"input your numbers"<<endl;
  reserve(j);
  return 0;
}

void reserve (int j)
{
  int a[20],i;
  for(i=0;i<j;i++)
    cin>>a[i];
  for(i=0;i<j;i++)
    cout<<a[i];
  cout<<"***************************************************"<<endl;
}

