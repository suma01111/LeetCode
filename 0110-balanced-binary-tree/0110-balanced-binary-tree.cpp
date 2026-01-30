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
public:
    bool balance = true;
    bool isBalanced(TreeNode* root) {
        height(root);
        return balance;
    }

    int height(TreeNode* node){
        if(node==NULL) return 0;

        int l = height(node->left);
        int r = height(node->right);
        
        if(abs(l-r)>1) balance = false; //IMP most
        return max(l,r)+1;
    }
};

/*
or every node in the tree:
|height(left subtree) - height(right subtree)| <= 1
*/