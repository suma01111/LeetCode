/*Approach 2 
    Kahn's Algorithm (BFS)
    - Compute indegree of every node.
    - Push all nodes with indegree 0 into queue.
    - Process queue:
         * Add node to answer.
         * Reduce indegree of neighbours.
         * Push neighbour if indegree becomes 0.
    - If topo size == total nodes -> return topo.
    - Else cycle exists -> return {}.*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list and indegree array
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]); // prerequisite -> course
            indegree[it[0]]++;
        }
        
        queue<int> q;// Push all nodes having indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        // BFS (Kahn's Algorithm)
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);// Current course can be taken now

            for (int nei : adj[node]) {// Remove all outgoing edges
                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // If all courses are processed, return topo order
        // Otherwise a cycle exists, so it's impossible
        if (topo.size() == numCourses)
            return topo;

        return {};
    }
};