/**
MAIN IDEA : if (abs(lh - rh) > 1)return -1; at any point of node
 Down ward code is more relevant in comments*/
 
class Solution {
    bool balance = true;
public:
    bool isBalanced(TreeNode* root) {
        height(root); //return balance
        return balance;
    }

    int height(TreeNode* node){
        if(node==NULL) return 0;

        int l = height(node->left);
        int r = height(node->right);
        
        if(abs(l-r)>1) balance = false; //IMP most, at any moment this cot viloted return false
        return max(l,r)+1;
    }
};
/*
or every node in the tree:
|height(left subtree) - height(right subtree)| <= 1
*/



/* -1 returning code 

 int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        if (lh == -1) return -1;      // Left subtree not balanced

        int rh = height(root->right);
        if (rh == -1) return -1;      // Right subtree not balanced

        if (abs(lh - rh) > 1)
            return -1;             // Current node not balanced,here -1 COMES

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
*/