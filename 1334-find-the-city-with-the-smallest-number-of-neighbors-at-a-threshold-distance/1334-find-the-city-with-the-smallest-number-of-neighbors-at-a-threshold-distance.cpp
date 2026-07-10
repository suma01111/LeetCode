/*
Approach:
1. Create an adjacency matrix and initialize all distances as INF.
2. Set dist[i][i] = 0.
3. Fill the given edges.
4. Apply Floyd-Warshall to compute shortest distance between every pair.
5. For each city, count how many cities are reachable within threshold.
6. Keep the city with the minimum count.
7. If counts are equal, choose the larger city index.
TC: O(n³)//3 loops, SC: O(n²)//adj matrix
*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n,vector<int>(n,INF));

        // Distance to itself = 0
        for (int i=0;i<n;i++)
            dist[i][i]=0;

        // Build adjacency matrix
        for (auto &it : edges) {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        // Floyd-Warshall
        for (int via=0;via<n;via++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {

                    if (dist[i][via]==INF || dist[via][j]==INF)
                        continue;

                    dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }

        int city=-1;
        int minReachable=INT_MAX;

        // Count reachable cities
        for (int i=0;i<n;i++) {
            int cnt=0;
            for (int j=0;j<n;j++){
                if (dist[i][j]<=distanceThreshold)
                    cnt++;
            }

            // If tie, choose larger city index
            if (cnt<=minReachable) {
                minReachable=cnt;
                city=i;
            }
        }

        return city;
    }
};