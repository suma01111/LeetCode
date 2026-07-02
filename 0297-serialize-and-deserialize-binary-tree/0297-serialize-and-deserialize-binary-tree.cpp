//BY PREORDER TRAVERSAL

/**
// Serialize:
// 1. Perform preorder traversal.
// 2. Store node value.
// 3. Store 'N' for NULL nodes.
// 4. Join everything using ','.

// Deserialize:
// 1. Split string by ','.
// 2. Read values one by one.
// 3. If value is 'N', return NULL.
// 4. Otherwise create node.
// 5. Recursively build left and right subtree.
 */


class Codec {
public:

    // Serialize using preorder DFS
    void dfs(TreeNode* root, string &ans) {
        if (!root) {
            ans += "N,";
            return;
        }
        ans += to_string(root->val) + ",";

        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans;
        dfs(root, ans);

        return ans;
    }

    // Build tree back using preorder sequence
    TreeNode* build(vector<string>& nodes, int &idx) {
        if (nodes[idx] == "N") {
            idx++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx++]));

        root->left = build(nodes, idx);
        root->right = build(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        for (char ch : data) {
            if (ch == ',') {
                nodes.push_back(temp);
                temp.clear();
            }
            else temp += ch;
        }

        int idx = 0;

        return build(nodes, idx);
    }
};