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
    unordered_set<int> set; 
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        

        if(set.count(k - root->val)) return true; // Check if complement exists
        
        set.insert(root->val);// Insert current value

        return findTarget(root->left,k)
            || findTarget(root->right,k);
    }
};