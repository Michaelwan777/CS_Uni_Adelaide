#include<iostream>
#include<string>
using namespace std;
void populateDatabase(string a[][3]);
void printDatabase(string a[][3]);
void getscore(string a[][3],string b);
int main()
{
  string a[15][3],b;
  cout<<"input the name,age and score\n";
  populateDatabase(a);
  printDatabase(a);
  cout<<"input the name of the student to be searched"<<endl;
  cin>>b;
  getscore(a,b);
  return 0;
}

void populateDatabase(string a[][3])
{
   for(int i=0;i<15;i++)
     { 
       cout<<"enter the no "<<i+1<<" student name,age and score"<<endl;
       for(int j=0;j<3;j++)
	 {
	   // cout<<"enter the no "<<i+1<<" student name,age and score"<<endl;
	   cin>>a[i][j];
	 }
     }
}

void printDatabase(string a[][3])
{
  for(int i=0;i<15;i++)
  {
    cout<<"the  no "<<i+1<<" student name,age and score are "<<endl;
    for(int j=0;j<3;j++)
    {
      cout<<a[i][j]<<"    ";
    }
    cout<<endl;
  }
  
}
void getscore(string a[][3],string b)
{
  int flag=0;
 for(int i=0;i<3;i++)
  {
    if (a[i][0]==b)
      {
	cout<<"the score is  "<<a[i][2]<<endl;
	flag=1;
      }
  }
    if (flag==0)
      cout<<b<<"  does not exit"<<endl;
  
}


















