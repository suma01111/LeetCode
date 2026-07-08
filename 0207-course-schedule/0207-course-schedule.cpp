//by cycle detection in directed graph approach
// Approach:
// Build adjacency list (as edge is given)
// Detect cycle using DFS + vis[] + pathVis[].
// If cycle exists -> cannot finish all courses.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it: prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }

        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]) {
                if(!dfs(i,vis,pathVis,adj)) return false;
            }
        }

        return true;
    }


    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj){
        vis[node]=1;
        pathVis[node]=1;  // Mark node in current DFS path

        for(auto it : adj[node]){
            if(!vis[it]){
                if(!dfs(it,vis,pathVis,adj)) // If a cycle is found in any recursive DFS call, immediately return it to the caller.
                    return false;
            }
            else if(pathVis[it]){ // Back edge found -> cycle exists
                return false;
            }
        }

        // Backtracking: remove node from current DFS path
        pathVis[node] = 0;

        return true;    // No cycle found from this node
    }
};