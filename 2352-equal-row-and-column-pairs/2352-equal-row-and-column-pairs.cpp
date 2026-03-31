class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        map<vector<int>, int> row;
        map<vector<int>, int> col;

        // store rows
        for(int i = 0; i < m; i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                temp.push_back(grid[i][j]);
            }
            row[temp]++;
        }

        // store columns
        for(int j = 0; j < n; j++) {
            vector<int> temp;
            for(int i = 0; i < m; i++) {
                temp.push_back(grid[i][j]);
            }
            col[temp]++;
        }

        int cnt = 0;

        // match rows with columns
        for(auto it : row) {
            if(col.find(it.first) != col.end()) {
                cnt += it.second * col[it.first];
            }
        }

        return cnt;
    }
};