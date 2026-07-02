/**
 // Approach:
// 1. Find the leftmost and rightmost heights of the current subtree.
// 2. If both heights are equal, the subtree is perfect.
//    Return (2^height - 1).
// 3. Otherwise, recursively count nodes in left and right subtrees.
// 4. Answer = 1 + left subtree + right subtree.
 */

 //optimal force in (logN)*(logN)

class Solution {
public:

    // Find height by moving to the leftmost node
    int findLeftHeight(TreeNode* node) {
        int height = 0;

        while (node) {
            height++;
            node = node->left;
        }

        return height;
    }

    // Find height by moving to the rightmost node
    int findRightHeight(TreeNode* node) {
        int height = 0;

        while (node) {
            height++;
            node = node->right;
        }

        return height;
    }

    //MAIN Function
    int countNodes(TreeNode* root) {

        if (!root) return 0;

        // Step 1: Find leftmost and rightmost heights
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        // Step 2: If heights are equal, it's a perfect binary tree
        if (lh == rh)
            return (1 << lh) - 1;//(2^height - 1).

        // Step 3: Otherwise recursively count left and right subtree
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};