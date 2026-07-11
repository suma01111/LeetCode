// for N vertices I need N-1 edge
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] =1;
        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour,adj,vis);
            }
        }
    }


public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1) return -1; // minimum edges needed = n-1

        vector<vector<int>> adj(n);
        //building graph
        for(auto e: connections){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        int comp =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                comp++;
            }
        }


        return comp-1;
    }
};