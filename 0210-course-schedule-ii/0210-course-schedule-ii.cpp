class Solution {
    bool dfs(int node, vector<vector<int>> &adj,
             vector<int> &vis, vector<int> &pathVis,
             vector<int> &ans){

        vis[node]=1;
        pathVis[node]=1;

        for(int nei: adj[node]){
            if(!vis[nei]){
                if(dfs(nei,adj,vis,pathVis,ans))
                    return true;
            }
            else if(pathVis[nei])
                return true;
        }
        // Remove node from current DFS path
        pathVis[node]=0;
        // Store node after visiting all its neighbours
        ans.push_back(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        vector<int> ans;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis,ans))
                    return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};