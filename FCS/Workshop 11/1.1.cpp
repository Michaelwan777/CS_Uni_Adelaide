#include<iostream>
using namespace std;
int main()
{
 int *t = new int;
 cout<<"*t  "<<*t<<"  "<<  sizeof(*t)<<endl;
 cout<<"t  "<<t<<"  "<< sizeof(t)<<endl;
 return 0;
}
