/**
// 1. Search for the node.
// 2. If node has no child, return NULL.
// 3. If node has one child, return that child.
// 4. If node has two children:
//      - Find leftmost node of right subtree.
//      - Attach left subtree there.
//      - Return right subtree.
 */
class Solution {
public:

    // Find leftmost node in a subtree
    TreeNode* findLastLeft(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root;
    }


    // Rearrange tree after deleting current node
    TreeNode* helper(TreeNode* root) {
        // No left child
        if (!root->left) return root->right;

        // No right child
        if (!root->right) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastLeft = findLastLeft(rightChild);

        // Attach left subtree
        lastLeft->left = root->left;

        return rightChild;
    }



    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root) return NULL;

        if (root->val == key)
            return helper(root);

        TreeNode* curr = root;

        while (curr) {
            if (key < curr->val) {
                if (curr->left && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                }
                curr = curr->left;
            }

            else {
                if (curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};