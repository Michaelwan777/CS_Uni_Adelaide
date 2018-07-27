#include<iostream>
using namespace std;
string reverse(string str);
int main()
{
  string str;
  cout<<"input"<<endl;
  cin>>str;
  cout << reverse(str) << endl;
  //string str1;
  //str1 = reverse(str)+str.substr(0,1);
  //cout << str1 << endl;

}
string reverse(string str)
{
    string word = "";

    if (str.length() <= 1)
    {
      return str;
      // cout<< str<<endl;
    }
    else
    {
        string str_copy = str;
        int n = str_copy.length()-1;
        string last_letter = str_copy.substr(n, 1);
	//	cout<<last_letter;
	str_copy = str_copy.substr(0, n);
	 word += reverse(str_copy);
	 return last_letter+reverse(str_copy);
    }
    //return word;
}
