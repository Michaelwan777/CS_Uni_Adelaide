#include<iostream>
using namespace std;
#include<stdlib.h>
int numberOfTwos();
int main()
{
  int j=0,a;
  numberOfTwos();
  return 0;
}




int numberOfTwos()
{
  srand(time(0));
  int j=0,a;
  for(int i=1;i<=3;i++)
    {
      a=1+rand()%6;
      if (a==2)
	j++;
      cout<<a<<endl;
    }
  cout<<"the amount of 2 is "<<j<<endl;
  return 0;
}

