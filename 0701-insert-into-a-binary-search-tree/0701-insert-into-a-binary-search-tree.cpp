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
//thier are many ways to insert, but insert at leaf node
 //where we have to store Node, so this will always be Leaf node
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //base case
        if(root==NULL) {
             return new TreeNode(val);
        }

        TreeNode* curr=root;
        while(true){
            if(curr->val <= val){
                if(curr->right!=NULL) curr=curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
        } 

            else{
                if(curr->left!=NULL) curr=curr->left;
                else{
                    curr->left= new TreeNode(val);
                    break;
                }
            }
        }

        return root ;
    }
};