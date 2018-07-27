#include<iostream>
using namespace std;
void output0to19(int num)
{
	switch(num)
	{
		case 0:break;
		case 1:cout<<"one ";break;
		case 2:cout<<"two ";break;
		case 3:cout<<"three ";break;
		case 4:cout<<"four ";break;
		case 5:cout<<"five ";break;
		case 6:cout<<"six ";break;
		case 7:cout<<"seven ";break;
		case 8:cout<<"eight ";break;
		case 9:cout<<"nine ";break;
		case 10:cout<<"ten ";break;
		case 11:cout<<"eleven ";break;
		case 12:cout<<"twelve ";break;
		case 13:cout<<"thirteen ";break;
		case 14:cout<<"fourteen ";break;
		case 15:cout<<"fifteen ";break;
		case 16:cout<<"sixteen ";break;
		case 17:cout<<"seventeen ";break;
		case 18:cout<<"eighteen ";break;
		case 19:cout<<"nineteen ";break;
		default:cout<<"Error by ouotput0to19()";break;
	}
	return;
}

void output0to99(int num)
{
	if(num>99)
	{
		cout<<"Error by output0to99()";
		return;
	}
		
	if(num<20)
	{
		output0to19(num);
		return;
	}
			
	int numoften=num/10;
	switch(numoften)
	{
		case 2:cout<<"twenty ";break;
		case 3:cout<<"thirty ";break;
		case 4:cout<<"fourty ";break;
		case 5:cout<<"fifty ";break;
		case 6:cout<<"sixty ";break;
		case 7:cout<<"seventy ";break;
		case 8:cout<<"eighty ";break;
		case 9:cout<<"ninety ";break;
		default:cout<<"Error by output0to99("<<numoften<<")";
	}
	numoften=num%10;
	output0to19(numoften);
	return;
}

void output0to999(int num)
{
	if(num>999)
	{
		cout<<"Error by output0to999()";
		return;
	}
	if(num<100)
	{
		output0to99(num);
		return;
	}
	
	int numofhundred=num/100;
	output0to99(numofhundred);
	cout<<"hundred ";
	output0to99(num%100);
	return;
}
void divide(int num,int a[4])
{
	//a[0] billion, a[1] million, a[2] thousand, a[3] other
	a[0]=num/1000000000;
	num=num%1000000000;
	a[1]=num/1000000;
	num=num%1000000;
	a[2]=num/1000;
	a[3]=num%1000;	
	return;
}

int main ()
{
	int n;
	cout<<"Input a 32-bit Integer:";
	cin>>n;
	if(n<0)
	{
		cout<<"minus ";
		n=n*(-1);
	}
	int a[4];
	divide(n,a);
	if(*a!=0)
	{
		output0to999(*a);
		cout<<"billion ";
	}
	if(*(a+1)!=0)
	{
		output0to999(*(a+1));
		cout<<"million ";
	}
	
	if(*(a+2)!=0)
	{
		output0to999(*(a+2));
		cout<<"thousand ";
	}
	
	output0to999(*(a+3));
	
	return 0;
}
