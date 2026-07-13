// Idea
// A closed island is an island of 0s that is completely surrounded by 1s.
// Key Observation
    // If an island of 0s touches the boundary, it cannot be closed.
    // So for every island:
    // DFS the whole island.
    // If during DFS we go outside the grid, the island is not closed.
    // Otherwise, if every DFS path stays inside the grid, it is a closed island.

class Solution {
public:

    bool dfs(int i,int j,vector<vector<int>>& grid){

        int m=grid.size();
        int n=grid[0].size();

        // Reached outside => island touches boundary
        if(i<0 || i>=m || j<0 || j>=n) //VERY IMP , MAIN IDEA
            return false;

        // Water or already visited doesn't break closedness
        if(grid[i][j]==1) return true; //IMPP

        // Mark visited
        grid[i][j]=1;

        // Island is closed only if ALL four directions remain closed
        bool left  = dfs(i,j-1,grid);
        bool right = dfs(i,j+1,grid);
        bool up    = dfs(i-1,j,grid);
        bool down  = dfs(i+1,j,grid);

        return left && right && up && down; //true should be from all directions
    }

    int closedIsland(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid))
                        cnt++;
                }
            }
        }

        return cnt;
    }
};