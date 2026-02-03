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

 //brute force O(n^2), simply compare to root  and insert 
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int start, int end){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(preorder[start]);

        // Find first element greater than root, IMPPP
        int idx = start+1;
        while (idx <= end && preorder[idx] < root->val)
            idx++;

        root->left = helper(preorder,start+1, idx-1); //Imp
        root->right = helper(preorder,idx, end); //IMP

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};


