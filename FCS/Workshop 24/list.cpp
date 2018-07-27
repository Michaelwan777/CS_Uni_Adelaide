#include<iostream>
using namespace std;
struct Node{
  int value;
  Node *next;
};

  Node *newNode(int newData,Node * newNext){
    Node *n=new Node;
    n->value=newData;
    n->next=newNext;
    return n;
}

void listprint(Node *p){
  int l=0;
  Node *temp=p;
  while(temp!=NULL){
    cout<<temp->value<<" ";
    temp = temp->next;
    l++;}
  cout<<"the length of list is  "<<l<<endl;
}

void listAddFront(Node* &head, Node* newNode){
  cout<<"add front......................."<<endl;
  newNode->next = head;
  head = newNode;
}

void listAddLast(Node* &head,Node* newNode){
  cout<<"add last......................."<<endl;
  Node *tempNode = head;
  Node *endoflist;
  while(tempNode->next!=NULL){
    tempNode=tempNode->next;
  }
  // cout<< tempNode -> value<<endl;
  tempNode->next = newNode;
  newNode->next = NULL;
}

Node* listFind(Node* head, int d){
  cout<<"finding...................."<<endl;
  int flag = 0;
  Node *temp = head;
  while(temp!=NULL){
    if(temp->value==d)
      {
       	cout<<" find value  "<<temp->value<<endl;
	flag = 1;
      }
    
      temp = temp->next;
  }
  if (flag == 1)
    return temp;
  else 
    return NULL;
}

void listDelete(Node* &head,int d){
  cout<<"delete....................."<<endl;
  Node* temp = head; 
  Node* prev;
  while(temp!=NULL){
    if(temp->value == d)
      {
	prev->next = temp->next;
	temp = temp->next;
      }
    else 
      {
	prev = temp;
	temp = temp->next;
      }
  }
}
int main()
{
  Node* head = NULL;
  Node* a = NULL;
  head = newNode(10,head);
  head = newNode(8,head);
  head = newNode(4,head);
  head = newNode(2,head);
  head = newNode(0,head);
  head = newNode(20,head);
  listprint(head);
  cout<<endl;
  cout<<endl;
  listAddFront(head,newNode(19,head));
  cout<<"added front"<<endl;
  listprint(head);
  cout<<endl;
  cout<<endl;
  cout<<"empty list"<<endl;
  listAddFront(a,newNode(13,a));
  listprint(a);
  cout<<"text"<<endl;
  listprint(head);
  listAddLast(head,newNode(14,head));
  cout<<"added last"<<endl;
  listprint(head);
  listFind(head,14);
  listDelete(head,8);
  listprint(head);
  return 0;
}
