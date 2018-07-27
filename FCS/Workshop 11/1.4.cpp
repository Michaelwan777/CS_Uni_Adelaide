#include<iostream>
using namespace std;
int main()
{
  int *arr = new int[3];
  int  a[4];
  cout<<sizeof(a)<<endl;;
 cout<< sizeof(arr)<<endl;
 cout<<sizeof(&arr[1])<<endl;
 cout<<arr<<endl;
 cout<<&arr[1]<<endl;
 cout<<&arr[2]<<endl;
 delete[] arr;
 cout<<arr<<endl;
 return 0;
}
