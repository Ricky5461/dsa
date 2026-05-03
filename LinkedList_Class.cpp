// USING CLASS  Basic linked list insertion and traversal 

#include<iostream>
using namespace std;

class Node {
    public:
            int data;
            Node * next;
            //constructor
            Node(int val){
                data=val;
                next=nullptr;
            }
    };

class LinkList{
    public:
            Node* head;
            LinkList(){
                head=nullptr;   // initially head is empty 
            }

            void InsertAtbegning(int val){
                Node * newNode = new Node(val);
                newNode->next=head;   // whatever the currently head is holding , store in heap memory
                head=newNode;    // Now head is pointing to newNode
            }

            void InsertAtEnd(int val){
                Node* newNode = new Node(val);
            if(head==nullptr){
                head=newNode;
                return ;
            }
                Node* temp=head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                    }
                    temp->next=newNode;
                    // newNode->next=nullptr;
                    //   free temp;
            }
            
            void Display(){
                Node* temp=head;
                while(temp!=nullptr)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->next;
                }
                // free temp;
            }
};

int main(){
    LinkList list;
    list.InsertAtbegning(10);
    list.InsertAtbegning(20);
    list.InsertAtbegning(30);
    list.InsertAtEnd(0);
    list.Display();
    return 0;
}