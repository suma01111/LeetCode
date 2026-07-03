/**
// 1. Every node has a valid range (min,max).
// 2. Initially range = (-∞,+∞).
// 3. Left child -> (min, root)
// 4. Right child -> (root, max)
// 5. If any node violates the range, return false.
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }

    bool helper(TreeNode* node, long long mini, long long maxi) {

        if(node == NULL)
            return true;

        if(node->val <= mini || node->val >= maxi) //range
            return false;

        return helper(node->left, mini, node->val) && //updating range while trav
               helper(node->right, node->val, maxi);
    }
};