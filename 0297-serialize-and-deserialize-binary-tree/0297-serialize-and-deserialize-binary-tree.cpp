//BY LEVEL ORDER (BFS)

// Serialize:
// 1. Perform level order traversal.
// 2. Store node values.
// 3. Store "N" for NULL nodes.
//
// Deserialize:
// 1. Read the root.
// 2. Use a queue.
// 3. For every node, assign its left and right child.
// 4. Push non-null children into the queue.

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr) {
                ans += "N,";
                continue;
            }

            ans += to_string(curr->val) + ",";

            q.push(curr->left);
            q.push(curr->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "N") return NULL;

        vector<string> nodes;
        string temp;

        for (char ch : data) {
            if (ch == ',') {
                nodes.push_back(temp);
                temp.clear();
            } else {
                temp += ch;
            }
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // Left child
            if (nodes[i] != "N") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            // Right child
            if (i < nodes.size() && nodes[i] != "N") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};