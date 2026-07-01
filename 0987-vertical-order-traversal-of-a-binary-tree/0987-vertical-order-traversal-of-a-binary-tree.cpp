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

        // FIX 1: unordered_map doesn't keep columns sorted.
        map<int, vector<pair<int,int>>> m;// HD -> {level, value}

        // FIX 2: Also store level (row) with each node.
        queue<pair<TreeNode*,pair<int,int>>> q;// node,{HD,level}
        q.push({root,{0,0}});

        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            TreeNode* node=curr.first;
            int HD=curr.second.first;
            int level=curr.second.second;

            m[HD].push_back({level,node->val});

            if(node->left) q.push({node->left,{HD-1,level+1}});
            if(node->right) q.push({node->right,{HD+1,level+1}});
        }

        for(auto &it:m){

            // FIX 3: Sort by level first, then value if level is same.
            sort(it.second.begin(),it.second.end());

            vector<int> col;
            for(auto x:it.second)
                col.push_back(x.second);

            ans.push_back(col);
        }

        return ans;
    }
};