#include<iostream>
include<string>
using namespace std;
void isPal(string str){
int length = str.length();
if(length <= 1) cout << "Palindrome" << endl;//check for zero or one digit numbers
else if(str.at(0) == str.at(length -1)) {
    str = str.substr(1, (length - 2));
    isPal(str);}
else cout << "Not a palindrome." << endl;{
    cin >> str;}
