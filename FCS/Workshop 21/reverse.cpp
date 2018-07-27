#include<iostream>
#include<string>
using namespace std;
void reverse(const string& str);
int main()
{
    string str;
    cout << " Please enter a string " << endl;
    cin>>str;
    reverse(str);
    return 0;    
}

void reverse(const string& str)
{
    int numOfChars = str.length();

    if(numOfChars == 1)
       cout << str << endl;
    else
    {
       cout << str[numOfChars - 1];
	  return reverse(str.substr(0, numOfChars - 1));
    }
}