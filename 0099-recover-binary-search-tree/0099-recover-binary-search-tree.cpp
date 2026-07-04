/**
// 1. Perform inorder traversal.
// 2. Keep previous node.
// 3. Whenever prev > curr,
//      detect swapped nodes.
// 4. If one violation:
//      swap(first,middle)
// 5. If two violations:
//      swap(first,last)
 */

class Solution {
public:
    TreeNode *first = NULL;
    TreeNode *middle = NULL;
    TreeNode *last = NULL;
    TreeNode *prev = NULL;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Violation
        if (prev && prev->val > root->val) {
            // First violation
            if (!first) {
                first = prev;
                middle = root;
            }
            // Second violation
            else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if (last)
            swap(first->val, last->val);
        else
            swap(first->val, middle->val);
    }
};