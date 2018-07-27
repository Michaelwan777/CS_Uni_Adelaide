#include<iostream>
#include<ctime>
using namespace std;
void clock(int a[],int h,int m, int s)
{
  int temp = m*60+s;
  int i = 0;
  while(a[i]*60-temp<0)
    {
      i++;
    }
  int range = a[i]*60-temp;
  if(temp == 0)
    cout<<h<<" o'clock"<<endl;
  if(temp>0&&temp<=60)
    cout<<"almost "<<h<<" o'clock"<<endl;
  if(temp>60&&temp<=240)
    cout<<"about "<<h<<" o'clock"<<endl;
  if(m>30)
    {
      if(range == 0)
	cout<<60-a[i]<<"  to  "<<h+1<<endl;
      if(range>240&&range<300)
	{
	  if(60-a[i]+5==15)
	    cout<<"almost quater to  "<<h+1<<endl;
	  else
	    cout<<"almost "<<60-a[i]+5<<" to "<<h+1<<endl;
	}    
      if(range>0&&range<=60)
	{
	  if(60-a[i]==15)
	    cout<<"almost quater to "<<h+1<<endl;
	  else
	    cout<<"almost  "<<60-a[i]<<" to  "<<h+1<<endl;
	}    
      if(range>60&&range<=180)
	{
	  if(60-a[i]+5==15)
	    cout<<"about quater to  "<<h+1<<endl;
	  else
	    {
	      if(60-a[i]+5==30)
		cout<<"about half past "<<h<<endl;
	      else
		cout<<"about"<<60-a[i]+5<<" to "<<h+1<<endl;
	    }     
	}
      if(range>180&&range<=240)
	{
	  cout<<a[i]<<endl;
	if(60-a[i]+5==15)
	  cout<<"almost quater to  "<<h+1<<endl;
	else
	  {
	    if(60-a[i]+5==30)
	      cout<<"almost half past "<<h<<endl;
	    else
	      cout<<"almost"<<60-a[i]+5<<" to "<<h+1<<endl;
	  }
	}
    }
  if(m<=30)
    {
      if(range == 0)
	{ 
	  if(a[i]==30)
	    cout<<" half past "<<h<<endl;
	  else
	    cout<<a[i]<<" past "<<h<<endl;
	}     
      if(range>240&&range<300&&m>=4)
	{
	  if(a[i]-5==15)
	    cout<<"almost quater past "<<h<<endl;
	  else
	    {
	      if(a[i]-5==30)
		cout<<"almost half past "<<h<<endl;
	      else
		cout<<"almost "<<a[i]-5<<" past "<<h<<endl;
	    }
	}
      if(range> 0&&range<=60&&m>=4)
	{
	  if(a[i]==15)
	     cout<<"almost quater past "<<h<<endl;
	  else
	    {
	      if(a[i]==30)
		cout<<"almost half past "<<h<<endl;
	      else
		cout<<"almost "<<a[i]<<"past"<<h<<endl;
	    }
	}
      if(range>60&&range<=180&&m>=4)
	{
	  if(a[i]-5==15)
	    cout<<"about quater past "<<h<<endl;
	  else
	    {
	      if(a[i]-5==30)
		cout<<"about half past "<<h<<endl;
	      else
		cout<<"about "<<a[i]-5<<" past "<<h<<endl;
	    }
	}
      if(range>180&&range<=240&&m>=4)
	{
	  if(a[i]-5==15)
	    cout<<"almost quater past "<<h<<endl;
	  else
	    {
	      if(a[i]-5==30)
		cout<<"almost half past "<<h<<endl;
	      else
		cout<<"almost "<<a[i]-5<<" past "<<h<<endl;
	    }
	}
    }
}
int main()
{
  int a[]={5,10,15,20,25,30,35,40,45,50,55,60};
  /* time_t tt=time(NULL);
  tm* t=localtime(&tt);
  cout<<"Year: "<<t->tm_year+1900<<
    " Month: "<<t->tm_mon+1<<
    " Day: "<<t->tm_mday<<
    " Hour: "<<t->tm_hour<<
    " Minute: "<<t->tm_min<<
    " Second: "<<t->tm_sec<<endl;
  clock(a,t->tm_hour,t->tm_min,t->tm_sec);
  return 0;
  */
  
  int h,m,s;
  cout<<"input h"<<endl;
  cin>>h;
  cout<<"input m"<<endl;
  cin>>m;
  cout<<"input s"<<endl;
  cin>>s;
  clock(a,h,m,s);
 
}
