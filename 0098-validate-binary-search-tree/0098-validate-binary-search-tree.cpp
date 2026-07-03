/**
// 1. Every node has a valid range (min,max).
// 2. Initially range = (-∞,+∞).
// 3. Left child -> (min, root)
// 4. Right child -> (root, max)
// 5. If any node violates the range, return false.
 */

class Solution {
public:

    bool solve(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        // Current node must lie within (low, high)
        if (root->val <= low || root->val >= high)
            return false;

        // Left subtree
        return solve(root->left, low, root->val) &&
               solve(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};