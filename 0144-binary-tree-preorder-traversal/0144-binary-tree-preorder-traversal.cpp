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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrderHelper(root, res);
        return res;
    }

    void preOrderHelper(TreeNode* node, vector<int>& res){
        if(node==NULL) return;
        res.push_back(node->val);
        preOrderHelper(node->left, res);
        preOrderHelper(node->right, res);

    }
};