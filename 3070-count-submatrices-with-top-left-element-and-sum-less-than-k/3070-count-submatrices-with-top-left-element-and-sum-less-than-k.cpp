class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = grid[0][0];
        int cnt =0;
        vector<vector<int>> prefix(m, vector<int>(n, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefix[i][j] = grid[i][j];
                if(i>0) prefix[i][j]+= prefix[i-1][j]; //top prefix sum
                if(j>0) prefix[i][j] += prefix[i][j-1];// left prefix sum
                if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1]; //minus diagonal repeatation

                if(prefix[i][j] <= k) cnt++;
            }
        }
        return cnt;
    }
};