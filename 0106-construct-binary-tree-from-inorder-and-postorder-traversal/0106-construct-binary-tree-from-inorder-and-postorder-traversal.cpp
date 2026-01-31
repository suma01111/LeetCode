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
    unordered_map<int, int> mp; //store inorder
    int postIdx ;

    //helper 
    TreeNode* solve(vector<int>& postorder, int inStart, int inEnd){
        // BASE CASE (MOST IMPORTANT)
        if (inStart > inEnd) return NULL;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];
        // IMPORTANT: build right first
        root->right = solve(postorder, mid + 1, inEnd);
        root->left  = solve(postorder, inStart, mid - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = inorder.size() - 1;
        //for O(1) search , putting inorder into map {node,index}
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(postorder, 0, inorder.size()-1);
    }
};