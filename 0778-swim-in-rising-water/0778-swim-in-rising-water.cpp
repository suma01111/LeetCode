class Solution {
public:
    vector<int> parent, size;

    // Find the ultimate parent (with Path Compression)
    int findParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // Merge two components using Union by Size
    void unionBySize(int pu, int pv) {
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    // Approach:
    // 1. Process cells in increasing order of their height.
    // 2. When a cell becomes available, mark it as active.
    // 3. Union it with all active neighbours.
    // 4. After every union, check if source (0,0) and
    //    destination (n-1,n-1) belong to the same component.
    // 5. The current height is the minimum time required.

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        parent.resize(n * n);
        size.assign(n * n, 1);

        for (int i = 0; i < n * n; i++)
            parent[i] = i;

        // {height, row, col}
        vector<vector<int>> cells;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        // Process cells in increasing height
        sort(cells.begin(), cells.end());

        vector<vector<int>> active(n, vector<int>(n, 0));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (auto &cell : cells) {
            int height = cell[0];
            int row = cell[1];
            int col = cell[2];

            active[row][col] = 1;

            int node = row * n + col;

            // Union with active neighbours
            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    active[nr][nc]) {

                    int adjNode = nr * n + nc;
                    int pu = findParent(node);
                    int pv = findParent(adjNode);

                    if (pu != pv)
                        unionBySize(pu, pv);
                }
            }

            // Source and destination connected
            if (findParent(0) == findParent(n * n - 1))
                return height;
        }

        return -1;
    }
};