//by cycle detection in directed graph approach
//topo vector added for topological sort (store value while backtracking and then reverse order will give topo order)

class Solution {
    bool dfs(int node, vector<vector<int>> &adj,
             vector<int> &vis, vector<int> &pathVis,
             vector<int> &topo){

        vis[node]=1;
        pathVis[node]=1;

        for(int nei: adj[node]){
            if(!vis[nei]){
                if(dfs(nei,adj,vis,pathVis,topo))
                    return true;
            }
            else if(pathVis[nei])
                return true;
        }
        // Remove node from current DFS path
        pathVis[node]=0;
        // Store node after visiting all its neighbours
        topo.push_back(node);
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
        vector<int> topo;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis,topo))
                    return {};
            }
        }
        reverse(topo.begin(),topo.end()); //just reverse array, as start pushed course can come before any course so put at last
        return topo;
    }
};


// The important point is:
// A node is added to ans only after all its neighbours (dependent courses) have been processed.