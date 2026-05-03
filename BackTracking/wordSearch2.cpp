#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    struct node{
        char c;
        int ends;
        node* child[26];
        string word;
    };
    node* getNode(char c){
        node* newNode = new node;
        newNode->c = c;
        newNode->ends=0;
        for(int i=0;i<26;i++){
            newNode->child[i] = nullptr;
        }
        newNode->word = "";
        return newNode;
    }
    node* root = getNode('/');

    void insert(string s){
        node* curr=root;

        int index=0;
        int i=0;
        while(s[i]){
            index = s[i]-'a';
            if(curr->child[index] == nullptr){
                curr->child[index] = getNode(s[i]);
            }
            curr=curr->child[index];
            i++;
        }
        curr->ends = curr->ends+1;
        curr->word=s;
    }
    void solve(vector<vector<char>>&board,int i,int j,int m,int n,vector<string>& ans,node* curr){
        int index = board[i][j]-'a';
        if(board[i][j] == '$' || curr->child[index]==nullptr){
            return;
        }
        curr = curr->child[index];
        if(curr->ends > 0){
            ans.push_back(curr->word);
            curr->ends -=1;
        }

        char c = board[i][j];
        board[i][j] = '$';

        if(i < m-1)solve(board,i+1,j,m,n,ans,curr);
        if(i > 0)solve(board,i-1,j,m,n,ans,curr);
        if(j < n-1)solve(board,i,j+1,m,n,ans,curr);
        if(j > 0)solve(board,i,j-1,m,n,ans,curr);
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       int m = board.size();
       int n = board[0].size();

       for(string s:words){
           insert(s);
       }

       vector<string>ans;
       for(int i = 0;i < m; i++){
        for(int j=0;j < n ;j++){
            solve(board,i,j,m,n,ans,root);
        }
       }
       return ans;
    }
};
int main(){
    Solution solution;
    vector<vector<char>> board = {
        {'a','b','c','d'},
        {'s','e','f','g'},
        {'h','i','j','k'},
        {'l','m','n','o'}
    };
    vector<string> words = {"abcb", "abc", "sea"};
    vector<string> result = solution.findWords(board, words);
    for(string s: result){
        cout << s << " ";
    }
    return 0;
}