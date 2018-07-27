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
  int a[3][3]={1,2,3,4,5,6,7,8,9},b[3][3];
  int (*p)[3];
  p=a;
  {
  for (int i=0; i<3; i++)
       {
                for (int j=0; j<3; j++)
                {
                           b[i][j]=*(*(p+i)+j);
                           cout<<b[i][j];      
                }
                cout<<endl;
       }
       a[0][0]=10;
       cout<<a[0][0]<<endl;
       cout<<b[0][0]<<endl;
	   p[0][0]=13;
       cout<<a[0][0]<<endl;
       cout<<b[0][0]<<endl;
      
  }
}