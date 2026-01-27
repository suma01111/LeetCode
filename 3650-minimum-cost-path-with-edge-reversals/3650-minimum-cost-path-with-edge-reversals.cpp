class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);

        // Step 1: Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});      // forward edge
            graph[v].push_back({u, 2 * w});  // reversed edge
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto &nbr : graph[node]) {
                int next = nbr.first;
                int wt = nbr.second;

                if (cost + wt < dist[next]) {
                    dist[next] = cost + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }
};
