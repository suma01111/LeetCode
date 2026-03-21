class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        
        for(int i = 0; i <= m - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                
                vector<int> temp;
                
                // Extract k x k submatrix
                for(int x = i; x < i + k; x++) {
                    for(int y = j; y < j + k; y++) {
                        temp.push_back(grid[x][y]);
                    }
                }
                
                // Sort elements
                sort(temp.begin(), temp.end());
                
                int mini = INT_MAX;
                bool found = false;
                
                // Find min difference between distinct elements
                for(int t = 1; t < temp.size(); t++) {
                    if(temp[t] != temp[t - 1]) {
                        mini = min(mini, temp[t] - temp[t - 1]);
                        found = true;
                    }
                }
                
                // If all elements same → answer = 0
                ans[i][j] = found ? mini : 0;
            }
        }
        
        return ans;
    }
};