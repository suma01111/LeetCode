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
//DFS allows us to compute path sums bottom-up, which is required to decide the best path at each node.

class Solution {
public:
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root); //give you updated val of maxSum
        return maxSum;
    }

    int dfs(TreeNode* node){
        if(node==NULL) return 0; //base case

    //max path from left & right(if negative comes it will be replacing with 0)
        int leftSum = max(0, dfs(node->left)); 
        int rightSum = max(0, dfs(node->right));

        maxSum = max(maxSum, node->val+leftSum+rightSum);

        return node->val + max(leftSum,rightSum); //REM return max downward path
    }
};