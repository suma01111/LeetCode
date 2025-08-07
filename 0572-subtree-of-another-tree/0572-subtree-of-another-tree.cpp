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
    //first find parent node same of tree and subroot
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(root->val==subRoot->val){
            if(isIdentical(root,subRoot)) return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot);
    }

    //check first nonidentical contions and at the if it is identical return true
public:
    bool isIdentical(TreeNode* node, TreeNode* subRoot){
        if(node == NULL && subRoot==NULL) return true;
        if(node==NULL || subRoot==NULL || node->val!=subRoot->val) return false;
        if(!isIdentical(node->left,subRoot->left)) return false;
        if(!isIdentical(node->right,subRoot->right)) return false;
        return true;
    }    
};