#include<iostream>
using namespace std;
int main()
{
int a;
cout<<"please enter your choice from 1-5"<<endl;
cin>>a;
switch(a)
{
case 1: cout<<"you choose the number 1"<<endl;break;
case 2: cout<<"you choose the number 2"<<endl;break;
case 3: cout<<"you choose the number 3"<<endl;break;
case 4: cout<<"you choose the number 4"<<endl;break;
case 5: cout<<"you choose the number 5"<<endl;break;
default: cout<<"error"<<endl;break;
}
return 0;
}