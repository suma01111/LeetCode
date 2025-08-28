class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Sort diagonals starting from first row (ascending)
        for (int col = 1; col < n; col++) {
            sortAsc(grid, 0, col);
        }

        // Sort diagonals starting from first column (descending)
        for (int row = 0; row < n; row++) {
            sortDesc(grid, row, 0);
        }

        return grid;
    }

private:
    // Sort diagonal in ascending order
    void sortAsc(vector<vector<int>>& grid, int row, int col) {
        int r = row, c = col;
        int n = grid.size();
        vector<int> diagonal;

        // collect diagonal
        while (r < n && c < n) {
            diagonal.push_back(grid[r++][c++]);
        }

        // sort ascending
        sort(diagonal.begin(), diagonal.end());

        // put back
        r = row; c = col;
        int i = 0;
        while (r < n && c < n) {
            grid[r++][c++] = diagonal[i++];
        }
    }

    // Sort diagonal in descending order
    void sortDesc(vector<vector<int>>& grid, int row, int col) {
        int r = row, c = col;
        int n = grid.size();
        vector<int> diagonal;

        // collect diagonal
        while (r < n && c < n) {
            diagonal.push_back(grid[r++][c++]);
        }

        // sort descending
        sort(diagonal.begin(), diagonal.end(), greater<int>());

        // put back
        r = row; c = col;
        int i = 0;
        while (r < n && c < n) {
            grid[r++][c++] = diagonal[i++];
        }
    }
};
