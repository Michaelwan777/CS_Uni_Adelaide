#include<iostream>
using namespace std;
int main()
{
  double a[3][3]={1,2,3,4,5,6,7,8,9};
  double *p;
  p=a[0];
  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
	{
	  cout<<*p<<"  ";
	  p++;
	}
      cout<<endl;
    }
  return 0;
}

