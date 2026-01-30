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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        //base case
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        
        bool left2Right = true; //IMP : flag 

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                int idx;
                if(left2Right) idx = i; //normal 
                else idx = size - 1 - i; //IMP: Reverse
                level[idx] = curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            ans.push_back(level);
            left2Right = !left2Right;  //flip direction (flag)
        }
        return ans;
    }
};