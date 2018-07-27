#include<iostream>
using namespace std;
struct student
{
  char name[50];
  int age;
  int score;
};
int main()
{
  student stu[15];
  for(int i=0;i<15;i++)
    {
      cout<<"input no "<<i+1<<" student's name, age and score \n";
      cin>>stu[i].name;
      cin>>stu[i].age;
      cin>>stu[i].score;
    }
  for(int j=0;j<15;j++)
    {
       cout<<"the  no "<<j+1<<" student's name, age and score is  \n";
       cout<<stu[j].name<<"   ";
       cout<<stu[j].age<<"   ";
       cout<<stu[j].score<<"   ";
       cout<<endl;
    }
  return 0;
}
