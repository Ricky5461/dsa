// ctrl+shift+L : to replace some word with other
// ctrl+d : to one by one occurence of word and after all select then replace enter
#include<iostream>
using namespace std;
 
class BinarySearchTree{
   private:
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

   Node* root;   //Constructor
   Node* Insert(Node *root,int val){
        if(root==nullptr){
            return new Node(val);
        }

        if(val<root->data){
            root->left=Insert(root->left,val);
        }
        else if(val>root->data)
        {
            root->right=Insert(root->right,val);
        }
       return root;// if node is have same valus as root data then it neither go left nor right
   }
   void PreOrderTravrs(Node* root){
        if(root==nullptr)return;
        cout<<root->data<<" ";
        PreOrderTravrs(root->left);
        PreOrderTravrs(root->right);
   }

   public:
        BinarySearchTree(){    // Constructor
            root=nullptr;
        }
        void InsertBST(int val){
            root = Insert(root,val);
        }
        void PreOrTrvers(){
            PreOrderTravrs(root);
        }
};
int main(){
    BinarySearchTree bst1;
    bst1.InsertBST(12);
    bst1.InsertBST(-34);
    bst1.InsertBST(900);
    bst1.InsertBST(3);
    bst1.InsertBST(45);
    cout<<"PreOrder Traversal of bst1: ";
    bst1.PreOrTrvers();

    BinarySearchTree bst2;
    bst2.InsertBST(300);
    bst2.InsertBST(8000);
    bst2.InsertBST(726376);
    bst2.InsertBST(-3233);
    bst2.InsertBST(0);
    cout<<"\nPreOrder Traversal of bst2: ";
    bst2.PreOrTrvers();
    return 0;
 }