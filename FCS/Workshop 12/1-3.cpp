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
  double a[9]={1,2,3,4,5,6,7,8,9};
  double * b=new double[9];
  b=a;
  for(int i=0;i<9;i++)
    cout<<b[i]<<"\t";
}