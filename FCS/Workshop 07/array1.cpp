#include<iostream>
using namespace std;
void reserve();
int main()
{
  cout<<"input 10 numbers"<<endl;
  reserve();
  return 0;
}

void reserve ()
{
  int a[100],i,j=0;
  for(i=0;i<=9;i++)
    cin>>a[i];
  cout<<"***************************************************"<<endl;
  for(int j=i-1;j>=0;j--)
  {
  	cout<<a[j]<<endl;
  }

  cout<<"*****************************************************"<<endl;
  for(int i=0;i<=9;i++)
  {
  	if(a[i]>10)
    
    {
    	cout<<a[i]<<endl;
	 	j++;
    }
  }
  cout<<"there are "<<j<<"numbers bigger than 10"<<endl;
}
