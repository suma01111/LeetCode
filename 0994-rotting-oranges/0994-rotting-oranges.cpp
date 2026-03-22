//shradhha sol , submission 2

class Solution {
public:
//Multi-Source BFS

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int,int>, int>> Q;// queue stores: {{i, j}, time}
        vector<vector<int>> visited(m, vector<int>(n, 0));//m*n mat of 0 or false

        //push rotton oranges in queue first(as a root of bfs)
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                Q.push({{i,j},0});
                visited[i][j]=1;
                }
            }
        }

        int ans=0;
        //bfs
        while(!Q.empty()){
            auto node = Q.front();
            Q.pop();

            int i= node.first.first;
            int j = node.first.second;
            int time = node.second;

            ans = max(ans, time);
            
            // up
            if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1){
                Q.push({{i-1, j}, time + 1});
                visited[i-1][j] = 1;
            }

            // left
            if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == 1){
                Q.push({{i, j-1}, time + 1});
                visited[i][j-1] = 1;
            }

            // down
            if(i+1 < m && !visited[i+1][j] && grid[i+1][j] == 1){
                Q.push({{i+1, j}, time + 1});
                visited[i+1][j] = 1;
            }

            // right
            if(j+1 < n && !visited[i][j+1] && grid[i][j+1] == 1){
                Q.push({{i, j+1}, time + 1});
                visited[i][j+1] = 1;
            }

        }

        //check if any fresh left
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]) return -1;
            }
        }

        return ans ;
    }
};