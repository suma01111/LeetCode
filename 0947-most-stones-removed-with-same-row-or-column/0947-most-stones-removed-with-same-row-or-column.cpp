// BY DSU

class Solution {
public:
    vector<int> parent, size;

    // Find the ultimate parent (with Path Compression)
    int findParent(int node) {
        if (node==parent[node])
            return node; 
        return parent[node]=findParent(parent[node]);
    }

    // Merge two components using Union by Size
    void unionBySize(int pu,int pv) {
        if (size[pu]<size[pv]) {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    // Approach:
    // 1. Treat every row and column as a DSU node.
    // 2. Offset the column index to avoid collision with row indices.
    // 3. Union the row node and column node for every stone.
    // 4. Count the number of connected components having at least one stone.
    // 5. Answer = Total Stones - Number of Components.

    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0, maxCol=0;

        // Find maximum row and column
        for (auto &it : stones) {
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }

        int totalNodes= maxRow + maxCol + 2; //IMPP

        parent.resize(totalNodes);
        size.assign(totalNodes,1);

        for (int i=0;i<totalNodes;i++)
            parent[i]=i;

        unordered_map<int,int> stoneNodes;

        // Union row node with column node
        for (auto &it : stones) {
            int rowNode=it[0];
            int colNode=it[1]+maxRow+1;

            int pu=findParent(rowNode);
            int pv=findParent(colNode);

            if (pu!=pv)
                unionBySize(pu,pv);

            stoneNodes[rowNode]=1;
            stoneNodes[colNode]=1;
        }

        int components=0;

        // Count connected components containing stones
        for (auto &it : stoneNodes) {
            if (findParent(it.first)==it.first)
                components++;
        }

        return stones.size()-components;
    }
};