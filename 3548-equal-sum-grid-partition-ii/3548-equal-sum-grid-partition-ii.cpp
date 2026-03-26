class Solution {
public:
    vector<vector<int>> rot(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> temp(n, vector<int>(m));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp[j][m - 1 - i] = grid[i][j];
            }
        }
        return temp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long tot = 0;

        // total sum
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                tot += grid[i][j];
            }
        }

        for(int k = 0; k < 4; k++){
            m = grid.size();
            n = grid[0].size();

            unordered_set<long long> st;
            st.insert(0);

            long long sum = 0;

            if(m < 2){
                grid = rot(grid);
                continue;
            }

            // single column case
            if(n == 1){
                for(int i = 0; i < m - 1; i++){
                    sum += grid[i][0];
                    long long diff = sum * 2 - tot;

                    if(diff == 0 || diff == grid[0][0] || diff == grid[i][0]){
                        return true;
                    }
                }
                grid = rot(grid);
                continue;
            }

            for(int i = 0; i < m - 1; i++){
                for(int j = 0; j < n; j++){
                    st.insert(grid[i][j]);
                    sum += grid[i][j];
                }

                long long diff = sum * 2 - tot;

                if(i == 0){
                    if(diff == 0 || diff == grid[0][0] || diff == grid[0][n - 1]){
                        return true;
                    }
                    continue;
                }

                if(st.count(diff)){
                    return true;
                }
            }

            grid = rot(grid);
        }

        return false;
    }
};