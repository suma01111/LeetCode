//Approach
// Color array:
// -1-> Not colored, 0-> First color, 1-> Second color
// Traverse every connected component.
// Start DFS/BFS from every uncolored node.
// Give source color 0.
// Every neighbour gets opposite color.
// If neighbour already has same color,
// return false.

class Solution {
    bool bfs(int start,vector<vector<int>>& graph,vector<int>& color){
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int nei:graph[node]){
                 if (color[nei]==-1) {
                    color[nei]=1-color[node];//HERE opposite color alloted
                    q.push(nei);
                }
                else if (color[nei]==color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if (!bfs(i,graph,color))
                    return false;
            }
        }
        return true;
    }
};