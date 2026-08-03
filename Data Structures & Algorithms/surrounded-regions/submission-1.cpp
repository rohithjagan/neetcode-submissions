class Solution {
public:
    int m,n;
    void dfs(vector<vector<char>>& board, int r, int c){
        board[r][c]='T';
        if(r+1<m && board[r+1][c]=='O'){
            dfs(board,r+1,c);
        }
        if(r-1>=0 && board[r-1][c]=='O'){
            dfs(board,r-1,c);
        }
        if(c+1<n && board[r][c+1]=='O'){
            dfs(board,r,c+1);
        }
        if(c-1>=0 && board[r][c-1]=='O'){
            dfs(board,r,c-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][n-1]=='O'){
                dfs(board,i,n-1);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j);
            }
            if(board[m-1][j]=='O'){
                dfs(board,m-1,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};
