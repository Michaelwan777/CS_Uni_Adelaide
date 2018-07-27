#include<iostream>
using namespace std;
struct Node{
  int value;
  Node *next;
};
class Stack{
private:
  // Node *temp;
public:
  Node* newNode(Node* p, int value);
  void pop(Node* &head);
  Node* push(Node* &head,int value);
  void print(Node* &head);
};

Node* Stack::newNode(Node* p, int value) {
  Node* n = new Node;
  n->value = value;
  n->next = p;
  return n;
}

void Stack::pop(Node* &head){
  cout<<"delete....................."<<endl;
  Node* temp1 = head; 
  Node* prev;
  while(temp1!=NULL){
    if(temp1->next == NULL)
      {	prev->next = NULL;}
	prev = temp1;
	temp1 = temp1->next;
  }
}

Node* Stack::push(Node* &head,int value){
  Node *tempNode = new Node;
    if(head==NULL){
      tempNode->value= value;
      tempNode->next=head;
      return tempNode;
    }
    else
      {
	tempNode = head;
	while(tempNode->next!=NULL){
	  tempNode=tempNode->next;
	}
	Node* p = new Node;
	tempNode->next = p;
	p->value = value;
	p->next = NULL;
	return head;
      }
}

void Stack::print(Node* &head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->value<<endl;
    temp=temp->next;
  }
}
int main()
{
  Node* head = NULL;

  Stack *a;
  // head = a->newNode(head, 100);
  // head = a->newNode(head, 90);
   head = a->push(head,10);
   head = a->push(head,9);
   a->print(head);
   cout<<endl;
   head = a->push(head,8);
   head = a->push(head,7);
   a->print(head);
   cout<<"after popping"<<endl;
   a->pop(head);
   a->print(head);
  return 0;
}
