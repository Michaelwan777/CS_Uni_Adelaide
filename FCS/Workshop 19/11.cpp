#include<iostream>
#include<vector>
#include<string>
#include"22.h"
using namespace std;

int main()
{ 
  vector<Animal>PetShop;
  Cat Cat1;
  Cat1.get_info("blue","mao","big","yy");
  Bird Bird1;
  Bird1.get_info("red","niao","bb","cc");
  PetShop.push_back(Cat1);
  PetShop.push_back(Bird1);
  PetShop.front().getname();
  for(int i=0;i<PetShop.size();i++)
    {
      cout<<PetShop[i].getname()<<endl;
      cout<<PetShop[i].getcolour()<<endl;
      cout<<endl;
    }
}
