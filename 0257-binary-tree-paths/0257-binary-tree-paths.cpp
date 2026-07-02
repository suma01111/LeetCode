/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if(root == nullptr) return;

        path+=to_string(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        path += "->";

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};

/*
dfs(1,"")

path = "1->"

│
├── dfs(2,"1->")
│
│   path = "1->2->"
│
│   ├── dfs(NULL,"1->2->")
│   │   Return
│   │
│   └── dfs(5,"1->2->")
│       path = "1->2->5"
│       Leaf
│       ans = ["1->2->5"]
│       Return
│
└── dfs(3,"1->")
    path = "1->3"
    Leaf
    ans =
    [
      "1->2->5",
      "1->3"
    ]
*/