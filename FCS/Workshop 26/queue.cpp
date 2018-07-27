#include<iostream>
using namespace std;
struct Node{
  int value;
  Node *next;
};
class Queue{
private:
  // Node *temp;
public:
  Node* dequeue(Node* &head);
  Node* enqueue(Node* &head,int value);
  void print(Node* &head);
};
Node* Queue::enqueue(Node* &head,int value)
{
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
Node* Queue::dequeue(Node* &head)
{
  Node* temp = head;
   temp = temp->next;
   head = temp;
   return head;
}

void Queue::print(Node* &head)
{
  Node* temp = head;
  while(temp!=NULL)
    {
      
      cout<<temp->value<<endl;
      temp=temp->next;
    }
}

int main()
{
  Node* head = NULL;
  Queue *queue;
  head = queue->enqueue(head,10);
  head = queue->enqueue(head,9);
  queue->print(head);
  cout<<endl;
  head = queue->enqueue(head,8);
  head = queue->enqueue(head,7);
  queue->print(head);
  cout<<endl;
  cout<<"after dequeue"<<endl;
   queue->dequeue(head);
   queue->print(head);
   //   queue->dequeue(head);
   //   queue->print(head);
   //cout << head;
  
}
