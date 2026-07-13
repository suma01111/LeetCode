class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size();
        int n=grid2[0].size();
        int cnt=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    if(dfs(i,j,grid1,grid2))
                        cnt++;
                }
            }
        }

        return cnt;
    }

    bool dfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        int m=grid2.size();
        int n=grid2[0].size();

        if(i<0 || i>=m || j<0 || j>=n || grid2[i][j]==0)
            return true;

        grid2[i][j]=0;

        bool ans=true;

        if(grid1[i][j]==0) ans=false; //REM

        ans &= dfs(i,j-1,grid1,grid2);
        ans &= dfs(i,j+1,grid1,grid2);
        ans &= dfs(i-1,j,grid1,grid2);
        ans &= dfs(i+1,j,grid1,grid2);

        return ans;
    }
};




// Intuition ==>> You are given two grids: grid1, grid2

// A sub-island is an island in grid2 whose every land cell (1) also lies on land in grid1.

// So for every island in grid2:

// Traverse the entire island using DFS.
// If any cell of that island is 0 in grid1, then it is not a sub-island.
// Otherwise, count it.