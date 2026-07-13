class Solution {
public:
    vector<int> tin, low, vis;
    vector<vector<int>> adj;
    vector<vector<int>> bridges;
    int timer = 1;

    // DFS using Tarjan's Algorithm
    void dfs(int node, int parent) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for (auto adjNode : adj[node]) {
            // Ignore the edge to parent
            if (adjNode == parent)
                continue;

            // Back Edge
            if (vis[adjNode]) {
                low[node] = min(low[node], tin[adjNode]);
            }
            else {
                dfs(adjNode, node);
                // Update low value
                low[node] = min(low[node], low[adjNode]);

                // Bridge Condition
                if (low[adjNode] > tin[node]) {
                    bridges.push_back({node, adjNode});
                }
            }
        }
    }

    // Approach:
    // 1. Build the adjacency list.
    // 2. Maintain tin[] and low[].
    // 3. Run DFS.
    // 4. If low[child] > tin[parent],
    //    then parent-child is a bridge.

    vector<vector<int>> criticalConnections(int n,vector<vector<int>>&  connections) {

        adj.resize(n);

        for (auto &it : connections) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        low.assign(n, 0);
        vis.assign(n, 0);
        dfs(0, -1);
        return bridges;
    }
};