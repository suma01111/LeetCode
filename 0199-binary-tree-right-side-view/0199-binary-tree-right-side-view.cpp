//Reverse =>. Preorder: Root L R)
//Right → Left -> root
 //BY dfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        dfs(root,0,output);//level start with 0
        return output;
    }
public:
    void dfs(TreeNode* node, int level, vector<int>& output){
        if(node==NULL) return;
        
        if(output.size()==level) output.push_back(node->val);//IMP REMEMBER
        //if(output.size() < level), level start from 1, another sol by MIK

        dfs(node->right,level+1, output);
        dfs(node->left,level+1, output);
    }
};