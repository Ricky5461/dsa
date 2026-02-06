
/** while link list insertion sort we braking the link and 
 * join the link instead of just swaping the values between them cause valu may be so big and swapiing will take
 * too much time so instead of it i used just breaking and linking technique */
#include<iostream>
using namespace std;

struct LLIS
{
    int val;
    LLIS* next;
    LLIS(){
        val=0;
        next=nullptr;
    }
    LLIS(int local_val){
        val=local_val;
        next=nullptr;
    }
    LLIS(int loc_val,LLIS* local_next){
        val=loc_val;
        next=local_next;
    }

};

LLIS* creatLinList(){
     int num;
      LLIS*temp;
      cin>>num;
      LLIS* nod=new LLIS(num);
      temp=nod;
    for(int i=0;i<6;i++){
        cout<<"enter the val=";
        cin>>num;
        LLIS* newNode=new LLIS(num,temp);
        temp=newNode;
    }
    LLIS* returnHead=temp;
    while(temp!=nullptr)
    {
        cout<<temp->val<<"\t";
        temp=temp->next;
    }
    return returnHead;
}
LLIS* Insertion_Sort(LLIS* head){
    
    if(head==nullptr || head->next==nullptr) return head;
    LLIS* prev=head;
    LLIS* curr=head->next;
    LLIS* dummy=new LLIS(0,head);

    while(curr!=nullptr){
        if(curr->val > prev->val){
            prev=curr;
            curr=curr->next;
            continue;
        }

        LLIS* temp=dummy;
        while (curr->val > temp->next->val)
        {
            temp=temp->next;
        }
        prev->next=curr->next;
        curr->next=temp->next;
        temp->next=curr;
        curr=prev->next;
    }
    return dummy->next;
}
int main(){

    LLIS* head=creatLinList();
    LLIS* Sorted_head=Insertion_Sort(head);
    LLIS* temp=Sorted_head;
    while (temp!=nullptr)
    {
        cout<<temp->val<<"\t";
        temp=temp->next;
    }
    return 0;
}