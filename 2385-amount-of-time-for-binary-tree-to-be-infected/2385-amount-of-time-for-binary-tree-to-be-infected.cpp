class Solution {
public:
    // Step 1: Build parent mapping and find the starting node
    TreeNode* buildParent(TreeNode* root, int start,
                          unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* startNode = nullptr;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start)
                startNode = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return startNode;
    }

    int amountOfTime(TreeNode* root, int start) {

        // Step 1: Build parent map and get start node
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = buildParent(root, start, parent);

        // Step 2: Start BFS from start node
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(startNode);
        vis.insert(startNode);

        int time = -1;

        while (!q.empty()) {

            int size = q.size();

            // Process one level (1 minute)
            while (size--) {

                TreeNode* curr = q.front();
                q.pop();

                // Visit left child
                if (curr->left && !vis.count(curr->left)) {
                    vis.insert(curr->left);
                    q.push(curr->left);
                }

                // Visit right child
                if (curr->right && !vis.count(curr->right)) {
                    vis.insert(curr->right);
                    q.push(curr->right);
                }

                // Visit parent
                if (parent.count(curr) && !vis.count(parent[curr])) {
                    vis.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }

            // One BFS level = One minute
            time++;
        }

        return time;
    }
};