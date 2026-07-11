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
    // 1. Treat every cell as a DSU node.
    // 2. Merge all adjacent land cells (1's) into islands.
    // 3. For every water cell (0), assume we flip it to 1.
    // 4. Collect the unique neighbouring island parents.
    // 5. Sum their sizes + 1 (current flipped cell).
    // 6. Keep the maximum possible island size.
    // 7. Handle the case when the grid already contains all 1's.

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        size.assign(n * n, 1);

        for (int i = 0; i < n * n; i++)
            parent[i] = i;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Merge all connected land cells
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0)
                    continue;

                int node = row * n + col;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        int pu = findParent(node);
                        int pv = findParent(adjNode);

                        if (pu != pv)
                            unionBySize(pu, pv);
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: Try converting every 0 into 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1)
                    continue;

                unordered_set<int> st;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;
                        st.insert(findParent(adjNode));
                    }
                }

                int totalSize = 1; // Current flipped cell

                for (auto parentNode : st)
                    totalSize += size[parentNode];

                ans = max(ans, totalSize);
            }
        }

        // Step 3: If grid already has all 1's
        for (int i = 0; i < n * n; i++) {
            ans = max(ans, size[findParent(i)]);
        }

        return ans;
    }
};