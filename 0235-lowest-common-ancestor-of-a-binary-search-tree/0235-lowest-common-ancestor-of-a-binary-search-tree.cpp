//APPROACH 2 : recursion (0(H)) TC

// 1. If both nodes are smaller, go left.
// 2. If both nodes are greater, go right.
// 3. Otherwise, current node is the LCA.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

/*
Approach	TC.     SC
Recursive	O(H)	O(H)
Iterative	O(H)	O(1)
*/
