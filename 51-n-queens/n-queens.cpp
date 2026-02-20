class Solution {
public:
    bool valid(int row , int col , vector<string>& board, int n){
        for(int i = row ; i>=0 ; i--){
            if(board[i][col]=='Q') return false;
        }

        for(int i = row , j = col ; i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }

        for(int i = row , j= col ; i>=0 && j<n ; i--,j++){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }


    void helper(int row ,  vector<vector<string>>& result , vector<string>& board,int n){
        if(row==n){
            result.push_back(board);
            return;
        }

        for(int col = 0 ; col < n ; col++){
            if(valid(row,col,board,n)){
                board[row][col] = 'Q';
                helper(row+1,result,board,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> result;
        helper(0,result,board,n);

        return result;
    }
};