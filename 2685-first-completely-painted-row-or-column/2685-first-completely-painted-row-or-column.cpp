class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();        
        int n = mat[0].size();     

        map<int, pair<int, int>> lookUp;

        // Populate the map with value -> (row, col) position
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                lookUp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowCount(m, 0);  
        vector<int> colCount(n, 0);  

        // Process the array 'arr' element by element
        for (int i = 0; i < m * n; i++) {
            pair<int, int> cell = lookUp[arr[i]];
            int r = cell.first;
            int c = cell.second;

            rowCount[r]++;
            colCount[c]++;

            // Check if any row or column is fully marked
            if (rowCount[r] == n || colCount[c] == m) {
                return i;  
        }
        }
        
        return -1;  
    }
};
