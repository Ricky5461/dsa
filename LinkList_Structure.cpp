
//using  STRUCTURE  Linked List implementation 
// member function of structutre is public bydefault and in class it is private default so need to  add public
// no need two class and wraper class ,no object
// in class structure we use member functuon but here function will be out of structure and call form anywhere

#include<iostream>
using namespace std;

struct Node {
      int data;
      Node* next;
      Node(int val){
        data=val;
        next=nullptr;
      } 
};

void InsertAtBegin(Node* &head, int val){  
    Node* newNode=new Node(val);
      newNode->next = head;
      head=newNode;
}
void InsertAtEnd(Node* &head,int val){
      Node* newNode=new Node(val);
      if(head==nullptr){
        head=newNode;
        return;
    }
    Node*temp=head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void Display(Node * head){

    while ((head!=nullptr))
    {
        cout<< head->data<<" ";
        head=head->next;
    }
    
}

 int main(){
     Node * head = nullptr;
     InsertAtBegin(head,12);
     InsertAtBegin(head,34);
     InsertAtBegin(head,234);
     InsertAtEnd(head,566);
     InsertAtEnd(head,3456);

     Display(head);
    return 0;
 }