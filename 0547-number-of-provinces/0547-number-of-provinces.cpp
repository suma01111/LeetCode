//dfs, first converting adj matrix to adj list, Approach-1

//Converting to an adjacency list takes O(n²) time, so for this problem it's actually more efficient to use the given adjacency matrix directly. 

class Solution {

    void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis) {
        vis[node]=true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei,adj,vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        // Convert adjacency matrix to adjacency list
        vector<vector<int>> adj(n);

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                //isConnected[i][i]=1,means a city is connected to itself
                if (i!=j && isConnected[i][j]==1) { 
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n,false);
        int provinces=0;

        for (int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                provinces++;
            }
        }
        return provinces;
    }
};

//The adjacency list version is mainly useful for learning or if you want a consistent DFS template across graph problems.