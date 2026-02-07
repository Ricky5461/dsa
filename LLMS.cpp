
// IMPLEMENTATION OF MERGE SORT USING LINKLIST
#include<iostream>
using namespace std;

struct LLMS{
    int val;
    LLMS * next;
    LLMS(){
        val=0;
        next=nullptr;
    }
    LLMS(int val1){
        val=val1;
        next=nullptr;
    }
    LLMS(int val1,LLMS*local){
        val=val1;
        next=local;
    }
};

LLMS* findMidl(LLMS*head){
    LLMS* slow=head;
    LLMS* fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

LLMS* merge(LLMS* low,LLMS* high){
    
    LLMS* temp;
    LLMS* left=low;
    LLMS* right=high;
    
        LLMS* dummy=new LLMS();
        temp=dummy;
    while(left!=nullptr && right!=nullptr){
        
        if(left->val <= right->val )
        { 
           temp->next=left ;
           temp=temp->next;
           left=left->next;

        }
        else{
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
    }
    while (left!=nullptr)
    {
        temp->next=left;
        temp=temp->next;
        left=left->next;
    }
    while (right!=nullptr)
    {
        temp->next=right;
        temp=temp->next;
        right=right->next;
    }
    temp=dummy->next;
    delete dummy;
    return temp;
}

LLMS*  merge_sort(LLMS* head,LLMS* tail){
    if(head==nullptr || head->next==nullptr)return head;

    LLMS* mid=findMidl(head);
    LLMS*midlinkToNext=mid->next;
    mid->next=nullptr;
    LLMS* low=merge_sort(head,nullptr);
    LLMS*high=merge_sort(midlinkToNext,tail);
    head = merge(low,high);
    return head;
}
int main(){
    LLMS* head;
    LLMS* newNode1 = new LLMS(24);
    LLMS* newNode2 = new LLMS(230,newNode1);
    LLMS* newNode3 = new LLMS(25,newNode2);
    LLMS* newNode4 = new LLMS(3421,newNode3);
    LLMS* newNode5 = new LLMS(2190,newNode4);
    LLMS* newNode6 = new LLMS(-9021,newNode5);
    LLMS* newNode7 = new LLMS(0,newNode6);
    head=newNode7;
    // while(head!=nullptr){cout<<head->val<<"\t";head=head->next;}
    LLMS *temp =merge_sort(head,nullptr);
    while(temp!=nullptr){cout<<temp->val<<"\t";temp=temp->next;}
    return 0;
}