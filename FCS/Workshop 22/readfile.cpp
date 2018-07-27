#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
 class Find
 {
 private:
   static int nbanana;
   static int nmorlocks;
   static int nvivid;
   static int ninspire;
   static int nporcelain;
   static int ntime;
   static int ndinosaur;
 public:
   void set_ban(){nbanana++;}
   void set_mor(){nmorlocks++;}
   void set_vivid(){nvivid++;}
   void set_ins(){ninspire++;}
   void set_por(){nporcelain++;}
   void set_ntime(){ntime++;}
   void set_ndin(){ndinosaur++;}
   void get_ban(){cout<<"there are "<<nbanana<<"  banana "<<endl;}
   void get_mor(){cout<<"there are "<<nmorlocks<<" Morlocks"<<endl;}
   void get_vivid(){cout<<"there are "<<nvivid<<" vivid"<<endl;}
   void get_ins(){cout<<"there are "<<ninspire<<" inspire"<<endl;}
   void get_por(){cout<<"there are "<<nporcelain<<" porcelain"<<endl;}
   void get_ntime(){cout<<"there are "<<ntime<<" time"<<endl;}
   void get_ndin(){cout<<"there are "<<ndinosaur<<" dinosaur"<<endl;}
 
  string findWord(string a[],int size,string find)
   {
     int flag=0;
     for(int i=0;i<size;i++)
       {
	 if(a[i]==find)
	   {
	     if(find=="banana")
	       {
		 set_ban();
		 flag=1;
	       }
	     
	     if(find=="Morlocks")
	       {
		 set_mor();
		 flag=1;
	       }
	     
	     
	     if(find=="vivid")
	       {
		 set_vivid();
		 flag=1;
	       }
	     
	     
	     if(find=="inspire")
	       {
		 set_ins();
		 flag=1;
	       }
	     
	     
	     if(find=="Porcelain")
	       {
		 set_por();
		 flag=1;
	       }
	     
	     
	     if(find=="time")
	       {
		 set_ntime();
		 flag=1;
	       }
	     
	     
	     if(find=="dinosaur")
	       {
		 set_ndin();
		 flag=1;
	       } 
	   }
       }
     if(flag==1)
       return find+"  "+"found";
     else
       return find+"  "+"not found";
   }
 };
int Find::nbanana=0;
int Find::nmorlocks=0;
int Find::nvivid=0;
int Find::ninspire=0;
int Find::nporcelain=0;
int Find::ntime=0;
int Find::ndinosaur=0;
int main()
{
  int i=0,j=0;
  string str;
  ifstream read("file.txt");
    if(read.is_open())
      {
	while(!read.eof())
	  {
	    read>>str;
	    i++;
	  }
      }
    read.close();
    string a[i];
    ifstream read2("file.txt");
    while(!read2.eof())
      {
	read2>>a[j];
	j++;
      }
    read2.close();
    Find aaa;
    cout<<aaa.findWord(a,i,"banana")<<endl;
    cout<<aaa.findWord(a,i,"Morlocks")<<endl;
    cout<<aaa.findWord(a,i,"vivid")<<endl;
    cout<<aaa.findWord(a,i,"inspire")<<endl;
    cout<<aaa.findWord(a,i,"Porcelain")<<endl;
    cout<<aaa.findWord(a,i,"time")<<endl;
    cout<<aaa.findWord(a,i,"dinosaur")<<endl;
    aaa.get_ban();
    aaa.get_mor();
    aaa.get_vivid();
    aaa.get_ins();
    aaa.get_por();
    aaa.get_ntime();
    aaa.get_ndin();
    return 0;
}

