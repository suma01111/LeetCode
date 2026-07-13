class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);

        for(auto it : edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(source,adj,destination,vis);
    }

    bool dfs(int node, vector<vector<int>>& adj,int &destination,vector<int> &vis){
        if (node==destination) return true;
        
        vis[node]=1;
        for(auto nei:adj[node]){
            if(!vis[nei]){
                if(nei==destination) return true;
                if(dfs(nei,adj,destination,vis)) return true;
            }
        }

        return false;
    }
};