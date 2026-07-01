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
        if(root==NULL) return {};

        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = true; //IMP : flag 

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                int idx;
                if(flag) idx = i; //normal 
                else idx = size - 1 - i; //IMP: Reverse

                level[idx] = curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            ans.push_back(level);
            flag =!flag;  //flip direction (flag)
        }
        return ans;
    }
};

/*
MY SOLution 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return{};
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;

        while(!q.empty()){

            vector<int> level;
            int sz=q.size();

                for(int i=0;i<sz;i++){
                    TreeNode* currNode=q.front();
                    q.pop();
                    level.push_back(currNode->val);
                    if(currNode->left) q.push(currNode->left);
                    if(currNode->right) q.push(currNode->right);
                }

            if(flag){
                ans.push_back(level);
                flag=false;
            }
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
                flag=true;
            }

        }
        return ans;
    }
};
*/