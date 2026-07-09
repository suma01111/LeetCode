/*
Approach:
1. If start or destination is blocked, return -1.
2. Start BFS from (0,0) with distance = 1.
3. Maintain a distance matrix initialized with INF.
4. Explore all 8 directions.
5. If a shorter distance is found, update and push into queue.
6. As soon as destination is reached, return its distance.
7. If BFS ends without reaching destination, return -1.

TC: O(N²),  SC: O(N²)
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // If source or destination is blocked, no path exists
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // dist[r][c] = shortest distance to reach cell (r,c)
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // {distance, {row, col}}
        queue<pair<int, pair<int, int>>> q;

        dist[0][0] = 1;              // Path starts from source itself
        q.push({1, {0, 0}});

        // 8 possible directions
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) { //bfs begins, dijsktra algo

            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // First time reaching destination is the shortest path (BFS property)
            if (row == n - 1 && col == n - 1)
                return dis;

            for (int i = 0; i < 8; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                // Check:
                // 1. nr, nc are inside a grid
                // 2. Cell is not blocked
                // 3. Found a shorter path
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 &&
                    dis + 1 < dist[nr][nc]) {

                    // Relax the distance
                    dist[nr][nc] = dis + 1;

                    // Push updated distance
                    q.push({dis + 1, {nr, nc}});
                }
            }
        }

        // Destination cannot be reached
        return -1;
    }
};

/*
Shortest path, Unweighted graph/grid, Minimum number of moves

👉 Think Dijkstra by bfs
Why?Because BFS explores level by level and
the first time we reach the destination, we are guaranteed to have found the shortest path.
*/