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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;
        
        map<int, vector<pair<int,int>>> mp; // col -> {row,value}
        queue<pair<TreeNode*, pair<int,int>>> q; // node , {col,row}
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int col = it.second.first;
            int row = it.second.second;
            
            mp[col].push_back({row,node->val});
            
            if(node->left)
                q.push({node->left,{col-1,row+1}});
            
            if(node->right)
                q.push({node->right,{col+1,row+1}});
        }
        
        for(auto &it : mp){
            auto vec = it.second;
            sort(vec.begin(), vec.end()); // sort by row then value
            vector<int> col;
            for(auto &p : vec)
                col.push_back(p.second);   
            ans.push_back(col);
        }
        return ans;
    }
};