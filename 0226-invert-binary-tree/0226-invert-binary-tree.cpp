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
    TreeNode* invertTree(TreeNode* root) {
        //base case 
        if(root == NULL) return NULL;

        invertTree(root->left);
        invertTree(root->right);

        //if we reached NULL end, then swaping will start
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};
//These recursive calls ensure that the inversion happens in a bottom-up manner, starting from the leaf nodes.