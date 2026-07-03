//APPROACH 1 : iterative 

// 1. If both nodes are smaller, go left.
// 2. If both nodes are greater, go right.
// 3. Otherwise, current node is the LCA.

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
