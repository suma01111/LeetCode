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
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* node){
        if(node==NULL) return 0; //base case

        //max path from left & right(if negative comes it will be replacing with 0)
        int left = max(0, dfs(node->left));  //zero for replacemnet -ve comes
        int right = max(0, dfs(node->right));

        maxSum = max(maxSum, node->val+left+right);

        return node->val + max(left,right); // return max downward path
    }
};