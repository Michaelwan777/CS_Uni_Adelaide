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
  double a[3][3]={1,2,3,4,5,6,7,8,9},b[3][3];
  for(int i=0;i<3;i++)
  {
    for (int j=0;j<3;j++)
      b[i][j]=a[i][j];
  }
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<b[i][j]<<"\t";
    }
    cout<<endl;
  }
}