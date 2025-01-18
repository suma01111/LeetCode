class Solution {
public:
    // Define a pair as (cost, (x, y))
    #define pip pair<int, pair<int, int>>

    // Check if the coordinate (x, y) is valid within the grid bounds
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();       // Number of rows
        int n = grid[0].size();    // Number of columns

        vector<vector<bool>> visited(m, vector<bool>(n, false)); // Track visited cells

        // Min-heap: stores (cost, x, y), where cost is the cumulative cost to reach (x, y)
        priority_queue<pip, vector<pip>, greater<pip>> minheap;
        minheap.push({0, {0, 0}}); // Start at (0, 0) with cost 0

        // Directions for right, left, down, up
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!minheap.empty()) {
            pip curr = minheap.top();  // Get the cell with the smallest cost
            minheap.pop();

            int cost = curr.first;    // Current cost
            int x = curr.second.first; // Current x-coordinate
            int y = curr.second.second; // Current y-coordinate

            // Skip if already visited
            if (visited[x][y]) 
                continue;

            // If we reached the bottom-right cell, return the cost
            if (x == m - 1 && y == n - 1) 
                return cost;

            // Mark the current cell as visited
            visited[x][y] = true;

            // Explore all 4 possible directions (Right, Left, Down, Up)
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                // If the new cell is valid and not visited
                if (isValid(newX, newY, m, n) && !visited[newX][newY]) {
                    int new_cost = cost; // Cost to reach the new cell

                    // If the current direction matches the grid's direction, cost is 0; otherwise, it's 1
                    new_cost += (i + 1 == grid[x][y]) ? 0 : 1;

                    // Push the new cell into the heap
                    minheap.push({new_cost, {newX, newY}});
                }
            }
        }

        return 0; // Return 0 if no path is found (though this case shouldn't occur for a valid grid)
    }
};


