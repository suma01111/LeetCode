// Approach 1: DFS/BFS 
//     Build an adjacency list.
//     Start DFS/BFS from city 1.
//     Visit every reachable city.
//     While traversing, keep updating the minimum edge weight seen.
// Time Complexity = O(n + m) ,  m = roads.length

class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<bool> &vis) {
        vis[node] = true;
        for (auto it : adj[node]) {
            int next = it.first;
            int dist = it.second;

            ans = min(ans, dist);

            if (!vis[next]) {
                dfs(next, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int d = r[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> vis(n + 1, false);
        dfs(1, adj, vis);
        return ans;
    }
};