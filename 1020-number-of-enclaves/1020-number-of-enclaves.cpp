// Start DFS/BFS from all boundary land cells.
// Mark all reachable land cells as visited (or convert them to water).
// Count the remaining land cells.
class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return;

        grid[r][c] = 0; // mark visited

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Remove lands connected to boundary
        for (int i = 0; i < m; i++) { 
            //first col and last col
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][n - 1] == 1) dfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            //first row and last row
            if (grid[0][j] == 1) dfs(grid, 0, j);
            if (grid[m - 1][j] == 1) dfs(grid, m - 1, j);
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans++; //inside the matrix counting 1
            }
        }

        return ans;
    }
};