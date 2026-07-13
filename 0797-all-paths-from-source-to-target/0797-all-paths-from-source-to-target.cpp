class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int node,vector<vector<int>>& graph) {
        if (node==graph.size()-1) {//reached to n-1th node then its destination
            ans.push_back(path);
            return;
        }

        for (int nei: graph[node]) {
            path.push_back(nei);
            dfs(nei,graph);
            path.pop_back();          // Backtrack
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(0,graph);
        return ans;
    }
};

// 0
// ├──1
// │   └──3
// └──2
//     └──3