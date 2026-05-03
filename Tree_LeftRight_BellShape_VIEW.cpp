#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Tree{
    int data;
    Tree* left;
    Tree* right;
    Tree(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

void LeftViewofTree(Tree* root,vector<int> &arr,int level,int *maxlevel){
   if(root==nullptr)return;
   
   if(*maxlevel<level){
        *maxlevel=level;
        arr.push_back(root->data);
   }
   LeftViewofTree(root->left,arr,level+1,maxlevel);
   LeftViewofTree(root->right,arr,level+1,maxlevel);
}

void RightViewofTree(Tree * root,vector<int> &arr,int level,int *maxlevel){
    if(root==nullptr)return ;

    if(*maxlevel<level){
        *maxlevel=level;
        arr.push_back(root->data);
    }
    RightViewofTree(root->right,arr,level+1,maxlevel);
    RightViewofTree(root->left,arr,level+1,maxlevel);
}
void Bell_Shape_ViewOfTree(Tree* root){
     vector<int>arr;
     arr.push_back(root->data);
     int maxlevel=0;int level=0;
     LeftViewofTree(root->left,arr,level+1,&maxlevel);

     reverse(arr.begin(),arr.end());
    maxlevel=0;
     RightViewofTree(root->right,arr,level+1,&maxlevel);
     for(int n:arr)cout<<n<<" ";
}
 int main(){
    Tree* root=new Tree(10);
    root->left=new Tree(6);
    root->right=new Tree(15);
    root->left->left=new Tree(3);
    root->left->right=new Tree(7);
    root->left->left->left=new Tree(-343);
    root->left->left->left->right=new Tree(0);
    root->right->right=new Tree(23);
    root->right->right->left= new Tree(20);
    root->right->right->left->left= new Tree(90);
    Bell_Shape_ViewOfTree(root);
    return 0;
 }