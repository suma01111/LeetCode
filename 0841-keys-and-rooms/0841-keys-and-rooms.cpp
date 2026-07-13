class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        dfs(0,rooms,vis);

        //final room check after dfs traversal
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }

        return true;
    }


    void dfs(int room, vector<vector<int>>& rooms, vector<int>& vis){
        vis[room]=1;

        for(int nei: rooms[room]){
            if(!vis[nei]) dfs(nei, rooms, vis);
        }
    }
};