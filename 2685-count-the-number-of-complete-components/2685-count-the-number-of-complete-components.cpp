 //complete component
// k nodes : every node connected to every other node
// Then total edges must be: k(k−1)/2

// ✅ Approach
    // Build adjacency list.
    // Maintain visited[].
    // For every unvisited node: Run DFS.=> Count nodes.
    // Add degree of every node.
    // Compute
    // actualEdges = degreeSum / 2
    // expectedEdges = nodes * (nodes-1) / 2
    // If equal, increment answer.


class Solution {
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, 
            int& nodesCnt, int &degreeSum){
        vis[node]=true;
        nodesCnt++;
        degreeSum+= adj[node].size();

        for(int nei: adj[node]){
            if(!vis[nei]){
                dfs(nei,adj,vis,nodesCnt,degreeSum);
            }
        }
    }


public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e: edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodesCnt=0;
                int degreeSum=0;

                dfs(i,adj,vis,nodesCnt, degreeSum);
                //got updated values of nodesCnt, degreeSum for this node

                int actualEdges=degreeSum/2;
                int expectedEdges=nodesCnt*(nodesCnt-1)/2;

                if (actualEdges==expectedEdges)
                    ans++;
            }
        }

        return ans;
    }
};