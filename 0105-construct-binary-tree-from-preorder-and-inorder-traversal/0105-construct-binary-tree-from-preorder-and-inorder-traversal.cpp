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
    unordered_map<int, int> mp;
    int preIdx = 0;

    //helper
    TreeNode* solve(vector<int>& preorder, int inStart, int inEnd){
        if (inStart > inEnd) return NULL; //Imp base case

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        
        int mid = mp[rootVal] ; //give index of node

        root->left = solve(preorder, inStart, mid-1);
        root->right = solve(preorder, mid+1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //for O(1) search , putting inorder into map {node,index}
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder, 0, inorder.size()-1);
    }
};