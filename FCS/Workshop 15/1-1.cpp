#include<iostream>
using namespace std;
class book
{
  string name;
  int number;
public:
  void setName(string bookName);
  string getName();
  void setPageNum(int pNum);
  int getPageNum();
};

int main()
{
  book book1;
  string name;
  int number;
  cout<<"input name"<<endl;
  cin>>name;
  cout<<"input pagenumber"<<endl;
  cin>>number;
  book1.setName(name);
  book1.setPageNum(number);
  cout<<"page is "<<book1.getPageNum()<<endl;;
  cout<<"name is  "<<book1.getName()<<endl;
  return 0;
}

void book::setName(string bookName)
{
  name=bookName;
}
string book:: getName()
{
  //cout<<"name is  "<<name<<endl;
   return name;
}
void book::setPageNum(int pNum)
{
  number=pNum;
}
int book::getPageNum()
{
  // cout<<"page number  is  "<<number<<endl;
  return number;
}
