//Approach 2- DSU 
//number of ultimate parent wil give us number of total number of compenet and , comp-1 extra edge we want

    // Approach:
    // 1. A connected graph with n nodes requires at least (n-1) edges.
    // 2. If edges < (n-1), return -1.
    // 3. Use DSU to connect components.
    // 4. If both nodes already have the same parent, it's an extra edge.
    // 5. Count the number of connected components.
    // 6. To connect k components, we need (k-1) edges.
    // 7. If extra edges >= required edges, return required edges.

class Solution {
public:
    vector<int> parent, size;

    // Find the ultimate parent (with Path Compression)
    int findParent(int node) {
        if (node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }

    // Merge two components (pu & pv are already ultimate parents)
    void unionBySize(int pu, int pv) {
        if (size[pu]<size[pv]) {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1) //for N size of graph, N-1 edge needed
            return -1;

        parent.resize(n);
        size.assign(n,1);

        for (int i=0;i<n;i++) parent[i]=i;

        int extraEdges=0;

        for (auto &it : connections) {
            int u=it[0];
            int v=it[1];

            int pu=findParent(u);
            int pv=findParent(v);

            // Edge forms a cycle
            if (pu==pv) extraEdges++;
            else {
                unionBySize(pu,pv);
            }
        }

        int components=0;

        // Count connected components
        for (int i=0;i<n;i++) {
            if(findParent(i)==i)
                components++;
        }

        return (extraEdges>=(components-1)) ? (components-1) : -1;
    }
};