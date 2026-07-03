/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // If both nodes are smaller, go left
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // If both nodes are larger, go right
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Nodes are on different sides OR one equals to root
            else {
                return root; 
            }
        }
        return NULL;
    }
};
