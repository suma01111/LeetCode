//Approach -1, dfs
//without converting into adj list, direct access to adj matrix
class Solution {

    void dfs(int node,vector<vector<int>>& isConnected,vector<bool>& vis) {
        vis[node]=true;

        for (int nei=0;nei<isConnected.size();nei++) {
    //Because every column represents a possible neighbor, trversing col of node
            if (isConnected[node][nei]==1 && !vis[nei]) { //IMPPP, new
                dfs(nei,isConnected,vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int provinces=0;

        for (int i=0;i<n;i++) {
            if (!vis[i]) {
                dfs(i,isConnected,vis);
                provinces++;
            }
        }

        return provinces;
    }
};