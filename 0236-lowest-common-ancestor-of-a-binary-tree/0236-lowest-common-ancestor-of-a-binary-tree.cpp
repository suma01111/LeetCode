/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case 
        if(root==NULL || root==p || root==q) return root;

        // store recursion results 
        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        if (leftNode == NULL) {
            return rightNode; //no matter if root.right is value or N, return it 
        }
        if (rightNode == NULL) {
            return leftNode;  
        }
        else {
            return root; //if left and right both are not null return their root
        }
        
    }
};