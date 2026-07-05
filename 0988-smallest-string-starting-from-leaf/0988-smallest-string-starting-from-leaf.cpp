/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//'~' All valid strings in this problem contain only lowercase letters:
    string ans = "~";   //126 larger than any lowercase string(97=a, 122=z)
    string path;

    void dfs(TreeNode* root) {
        if (!root) return;

        path.push_back(root->val+'a');

        if (!root->left && !root->right) {
            string cur(path.rbegin(),path.rend()); // leaf -> root
            if (cur<ans) ans=cur;
        }

        dfs(root->left);
        dfs(root->right);
        path.pop_back(); // backtrack
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};