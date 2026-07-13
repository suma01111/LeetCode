//FLOOF FILL concept
// Approach (DFS)
    // Traverse all boundary cells.
    // If boundary cell is 'O', DFS from it.
    // Mark every reachable 'O' as safe (e.g. '#').
    // Traverse entire board:
    // 'O' → 'X'
    // '#' → 'O'
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();

        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!='O')
            return;

        board[i][j] = '#';

        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        // First & Last Column
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][n-1]=='O') dfs(i,n-1,board);
        }

        // First & Last Row
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(0,j,board);
            if(board[m-1][j]=='O') dfs(m-1,j,board);
        }

        // Convert cells
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(board[i][j]=='O')
                    board[i][j]='X';

                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};