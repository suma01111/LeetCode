// Intuition : for terminal node 
// A node is safe if no path from it reaches a cycle.
//UNSAFE => If DFS reaches a cycle → current node is UNSAFE.
//SAFE => If DFS finishes without finding a cycle → current node is SAFE.


class Solution {

    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis, vector<int>& pathVis,
             vector<int>& check){

        vis[node]=1;
        pathVis[node]=1;

        // Assume unsafe until DFS proves otherwise
        check[node]=0;

        for(int nei: graph[node]){
            if(!vis[nei]){
                if(dfs(nei,graph,vis,pathVis,check)) //cycle detected->true
                    return true;
            }
            else if(pathVis[nei]){
                return true;
            }
            // Neighbour already known to be unsafe
            else if(check[nei]==0){ //vis hai, pathVis nhi h
                return true;
            }
        }
        // Remove node from current DFS path
        pathVis[node]=0;

        // No cycle reachable from this node
        check[node]=1;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> check(n,0); // 1=Safe(no cylce), 0=Unsafe(cycle)

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,check);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i]==1)
                ans.push_back(i); //ans carry no cycle 
        }

        return ans;
    }
};