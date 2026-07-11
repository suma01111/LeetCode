// Approach 2: BY DSU (disjoint set union)

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
    void unionBySize(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v) return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }

    // Approach:
    // 1. Initially, every city is its own province.
    // 2. Traverse the adjacency matrix.
    // 3. If city i and j are directly connected, merge their sets using DSU.
    // 4. After all unions, count how many nodes are their own parent.
    // 5. That count is the number of provinces.

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i;

        // Traverse only the upper triangle to avoid duplicate edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // If two cities are directly connected, merge them
                if (isConnected[i][j] == 1) {
                    unionBySize(i, j);
                }
            }
        }

        int provinces = 0;

        // Every ultimate parent represents one province
        for (int i = 0; i < n; i++) {
            if (findParent(i)==i)
                provinces++;
        }

        return provinces;
    }
};