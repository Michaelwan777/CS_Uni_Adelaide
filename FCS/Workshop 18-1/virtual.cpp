#include<iostream>
#include<string>
using namespace std;
class Animal
{
protected:
   string m_name;
  string colour;
  string name;
  string type;
  string sound;
public:

  void get_info(string a,string b,string c,string d );
  void show();
  string getname();
  virtual void getsound(){cout<<"biubiubiu"<<endl;}
};
class Cat:public Animal
{
protected:
  string m_name;
public:
  Cat()
  {
    m_name="Nyan Cat";
  }
  string getAlias()
  {
    return m_name;
  }
};
class Bird:public Animal
{
protected:
  string apprance;
public:
  Bird(void)
  {
    apprance="handsome";
    // cout<<"i am handsome"<<endl;
  }
  string get_apprance()
  {
    return apprance;
  }

  void getsound()
  {
    cout<<"i can bark"<<endl;
  }
};
void Animal::get_info(string a,string b,string c,string d)
{
  colour=a; 
  name=b;
  type=c;
  m_name=d;
}
string Animal::getname()
{
  return name;
}
void Animal::show()
{
  cout<<"color is  "<< colour<<endl;
  cout<<"name is  "<< name<<endl;
  cout<<"type is  "<< type<<endl;
}
int main()
{
  Animal *a= new Bird() ;
  a->get_info("blue","spy","big","yy");
  a->show();
  cout<<endl;
  cout<<endl;
  Bird b;
  b.get_info("red","eagle","grand","tt");
  b.show();
  b.getsound();

  Cat Fluffy; 
  Fluffy.get_info("zz","xx","cc","dd");
  cout<< Fluffy.getname()<<endl;
  cout<<Fluffy.getAlias()<<endl;
}
