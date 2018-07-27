#include<iostream>
#include<string>
using namespace std;
bool palindrome(string word);
int main()
{
    string word;
	cout << "input word"<<endl;
	cin>>word;

    if (palindrome(word) == true)
        cout << "word is a palindrome!" << endl;
    else
        cout << "word is not a palindrome..." << endl;

    return 0;
}

bool palindrome(string word)
{
    int length = word.length();
//	cout<<length<<endl;		
    string first = word.substr(0,1);
    string last = word.substr((length - 1), 1);

    if (first == last)
    {
        word = word.substr(1, (length - 2));
        cout << word << " " << word.length() << endl;  // DEBUGGING
        if (word.length() <= 1) return true;  // Problem line?
       return palindrome(word);
    }
    else
        return false;
}