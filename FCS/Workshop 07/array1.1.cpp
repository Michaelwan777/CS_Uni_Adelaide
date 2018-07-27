#include<iostream>
using namespace std;
void reserve();
void search();
int main()
{
  search();
  return 0;
}

/*void reserve ()
{
  int a[10],i,j=0;
  for(i=0;i<=9;i++)
    cin>>a[i];
}
*/
void search()
{
  int a[10],v;
  cout<<"enter the v\n";
  cin>>v;
  cout<<"enter 10 int\n";
  for (int i=0;i<=9;i++)
    cin>>a[i];
  cout<<"***********************************************************"<<endl;
  for(int i=0;i<10;i++)
    {
      if (a[i]==v)
	{    for (;i<9;i++)
	     { 
	       a[i]=a[i+1];
	     }
	  a[9]=0;
	}
    }
  // a[9]=0;
  for(int i=0;i<10;i++)
    cout<<a[i]<<endl;
}
