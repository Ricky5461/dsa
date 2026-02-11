#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

Node* insert(Node * root,int val){
    if(root==nullptr){
        return new Node(val);
    }
    
    if(val < root->data){
        root->left=insert(root->left,val);
    }
    else if(val > root->data){
        root->right=insert(root->right,val);
    }
    return root;
}

void PreOrTrav(Node* root){
    // Root left Right traversal method
    if(root==nullptr)return;
    cout<<root->data<<" ";
    PreOrTrav(root->left);
    PreOrTrav(root->right);
}
void PostOrderTraversal(Node* root){
    if(root==nullptr) return ;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}
void InOrderTraversal(Node * root){
    if(root==nullptr) return;
    InOrderTraversal(root->left);
    cout<< root->data<<" ";
    InOrderTraversal(root->right);
}
int main(){
// By using structure BST Tree
     Node* root=nullptr;
     root=insert(root,23);
     insert(root,-89);
     insert(root,45);
     insert(root,3);
     insert(root,3456);
     insert(root,0);
     //Traversal method
     PreOrTrav(root);
     PostOrderTraversal(root);
     InOrderTraversal(root);

    return 0;
}