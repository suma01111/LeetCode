// striver sol


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        
        // push all rotten oranges
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        
        int ans = 0;
        
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            int i = node.first.first;
            int j = node.first.second;
            int time = node.second;
            
            ans = max(ans, time);
            
            for(int k=0;k<4;k++){
                int ni = i + drow[k];
                int nj = j + dcol[k];
                
                if(ni>=0 && ni<m && nj>=0 && nj<n &&
                   !vis[ni][nj] && grid[ni][nj]==1){
                    
                    vis[ni][nj] = 1;
                    q.push({{ni,nj}, time+1});
                }
            }
        }
        
        // check any fresh left
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j])
                    return -1;
            }
        }
        
        return ans;
    }
};