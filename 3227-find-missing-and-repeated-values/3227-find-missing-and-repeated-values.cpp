class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();  // Grid is n x n
        int N = n * n;  // Total numbers expected from 1 to N
        vector<bool> present(N + 1, false);  // Track which numbers are present
        int repeating = -1, missing = -1;
        
        // Step 1: Process the 2D grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                if (present[val]) 
                    repeating = val;  // Duplicate number found
                present[val] = true;
            }
        }
        
        // Step 2: Find the missing number
        for (int i = 1; i <= N; ++i) {
            if (!present[i]) {
                missing = i;
                break;
            }
        }
        
        return {repeating, missing};
    }
};
