class Solution {
public:
    
    //Inspired By Raj Vikramaditya YT Channel TuF\U0001f601
    bool isTrue(vector<vector<char>>&board){
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isVal(board,i,j,c)){
                            board[i][j]=c;
                            if(isTrue(board)==true) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isVal(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c) return false;
            if(board[i][col]==c) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        isTrue(board);
    }
};