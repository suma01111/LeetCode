class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        deque<pair<int,int>> dq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Starting cost
        dist[0][0] = grid[0][0];

        dq.push_front({0,0});

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!dq.empty()) {

            auto [x,y] = dq.front();
            dq.pop_front();

            for(int k=0;k<4;k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx<0 || ny<0 || nx>=n || ny>=m)
                    continue;

                int newCost = dist[x][y] + grid[nx][ny];

                // Found a better path
                if(newCost < dist[nx][ny]) {

                    dist[nx][ny] = newCost;

                    // Zero-cost edge
                    if(grid[nx][ny] == 0)
                        dq.push_front({nx,ny});

                    // Cost = 1 edge
                    else
                        dq.push_back({nx,ny});
                }
            }
        }

        return dist[n-1][m-1] < health;
    }
};