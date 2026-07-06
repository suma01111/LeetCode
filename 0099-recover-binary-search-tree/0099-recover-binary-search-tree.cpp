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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        // Violation found
        if (prev!=NULL && prev->val>root->val) {

            // First violation
            if (first==NULL) first=prev;

            // Update second for both first and second violations
            second=root;
        }

        prev=root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }
};