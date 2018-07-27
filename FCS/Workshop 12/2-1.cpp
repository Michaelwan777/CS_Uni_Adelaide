#include<iostream>
using namespace std;
void array1();
int main()
{
  array1();
  return 0;
}
void array1()
{
  int a[10]={1,2,3,4,5,6,7,8,9,10};
  int *b=new int[10];
  b=a;
  for(int i=0;i<=9;i++)
  {
    if((i+1)%2==0)
      cout<<b[i]<<"   ";
    
  }
}