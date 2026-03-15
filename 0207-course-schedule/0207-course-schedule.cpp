class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
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
        pathVis[node]=1;

        for(auto it : adj[node]){

            if(!vis[it]){
                if(!dfs(it, vis, pathVis, adj))
                    return false;
            }

            else if(pathVis[it]){
                return false;
            }
        }

        pathVis[node] = 0;
        return true;
    }
};