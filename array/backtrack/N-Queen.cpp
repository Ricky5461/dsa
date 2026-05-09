#include<iostream>
using namespace std;
#include<vector>
#include<string>    

class Solution {
public:
        bool stateSpaceTree(int col,int row,vector<string>&board,int n){
            int c = col;
            int r = row;
            //Dagogonal   upward
                /*
                   \
                    \
                     \
                */
            while(c>=0 && r>=0){
                if(board[r][c]=='Q'){
                    return false;
                }
                r--;c--;
            }
            r = row;
            c = col;
            //Dagogonal   downvard
                /*
                      /
                     /
                    /
                */
            while(r<n && c>=0){
                if(board[r][c]=='Q'){
                    return false;
                }
                r++;
                c--;
            }
            r = row;
            c  =col;
            //Dagogonal   
                /*
                   ------ <= left
                */
            while(c>=0){
                if(board[r][c]=='Q'){
                    return false;
                }
                c--;
            }
            return true;
        }
        void func(int col,vector<vector<string>>&ans,vector<string>&board,int n){
            if(col==n){
                ans.push_back(board);
                return ;
            }
            for(int row=0;row<n;row++){
                if(stateSpaceTree(col,row,board,n)){
                   board[row][col] = 'Q';
                   func(col+1,ans,board,n);
                   board[row][col] = '.';
                }
            }
        }
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>>ans;
         vector<string>board(n);
         string s(n,'.');
         for(int i=0;i<n;i++){
            board[i] = s;
         }
         func(0,ans,board,n);
         return ans;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    vector<vector<string>>ans = s.solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
}   
