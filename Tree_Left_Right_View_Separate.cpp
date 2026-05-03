#include<bits/stdc++.h>
using namespace std;
   struct LVT{
        int data;
        LVT* left;
        LVT* right;
        LVT(int val){
            data=val;
            left=nullptr;right=nullptr;
        }
    };

// this function is for left view of a Tree
void LeftViewFunc(LVT* roo,int l,int *ml){
    if(roo==nullptr)return;

    if(*ml<l){
        cout<< roo->data<<" ";
        *ml=l;
    }
    LeftViewFunc(roo->left,l+1,ml);
    LeftViewFunc(roo->right,l+1,ml);
}

// This function print all right view view of Tree element
void RightViewFunc(LVT* Root,int l,int * ml){
    if(Root==nullptr) return ;
    if(*ml<l){
        cout<<Root->data<<" ";
        *ml=l;
    }
    RightViewFunc(Root->right,l+1,ml);
    RightViewFunc(Root->left,l+1,ml);
}
int main(){
    LVT* root= new LVT(100);
    root->left= new LVT(200);
    root->right=new LVT(240);

    root->left->left=new LVT(590);
    root->left->right= new LVT(345);
    root->right->left= new LVT(32);
    root->right->right= new LVT(908); 
    root->right->left->right=new LVT(4);


/** 
        100
       /    \ 
    200     240
              \
               908
**/
int l=1;int ml=0;
cout<<"This will be Left View of Tree"<<endl;
       LeftViewFunc(root,l,&ml);
       ml=0;
cout<<"\nThis will be Right view of Tree"<<endl;
       RightViewFunc(root,l,&ml);

return 0;
}