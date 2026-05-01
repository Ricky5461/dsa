class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool var=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               var = func(board,i,j,m,n,word,0);
               if(var)return true;
            }
        }
        return false;
    }
    bool func(vector<vector<char>>& board,int row,int col,int m,int n,string &word,int k){
        if(k==word.size()-1){
            if(board[row][col]==word[k])return true;
        }
        if(row < 0 || col < 0 || row >=m || col >= n)return false;
        if(board[row][col]==word[k]){
            board[row][col]='*';
            bool Pathfind = false;
            if(col < n-1 && k < word.size()){
                if(board[row][col+1]==word[k+1]){
                    Pathfind=func(board,row,col+1,m,n,word,k+1);
                    if(Pathfind){
                        board[row][col]=word[k];
                        return true;
                        }
                }
            }
            if(row < m-1 && k < word.size()){
                if(board[row+1][col]==word[k+1]){
                    Pathfind = func(board,row+1,col,m,n,word,k+1);
                    if(Pathfind){
                        board[row][col]=word[k];
                        return true;
                    }
                }
            }
            if(col>0 && k < word.size()){
                if(board[row][col-1]==word[k+1]){
                    Pathfind = func(board,row,col-1,m,n,word,k+1);
                    if(Pathfind){
                        board[row][col]=word[k];
                        return true;
                        }
                }
            }
            if(row >0 && k < word.size()){
                if(board[row-1][col]==word[k+1]){
                    Pathfind = func(board,row-1,col,m,n,word,k+1);
                    if(Pathfind){
                        board[row][col]=word[k];
                        return true;
                    }
                }
            }
            board[row][col]=word[k];
        }
        return false;
    }
};
