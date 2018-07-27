#include<iostream>
#include<vector>
using namespace std;
int main()
{
  vector<vector <string> > a(15,vector <string> (3));
  for(int i=0;i<3;i++)
     { 
       cout<<"enter the no "<<i+1<<" student name,age and score"<<endl;
       for(int j=0;j<3;j++)
	 {
           getline(cin,a[i][j]);
	 }
     }
  for(int i=0;i<3;i++)
    {
      cout<<"the  no "<<i+1<<" student name,age and score are "<<endl;
      for(int j=0;j<3;j++)
	{
	  cout<<a[i][j]<<"    ";
	}
      cout<<endl;
    }
}
