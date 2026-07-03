/**
// 1. Perform DFS (Root → Left → Right).
// 2. Whenever a level is visited for the first time,
//    store that node.
// 3. Since left is visited before right,
//    the first node at every level is the leftmost node.
// 4. Return the last stored value.
 */
class Solution {
    //DFS, level order traversal
    //Visit the Left subtree before the Right subtree, and store only the first node seen at every level.
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> res;
        recursion(root,0,res);
        return res.back(); //returns the last element of the vector res.
    }

public:
    void recursion(TreeNode* node, int level, vector<int>& res){
        if(node==NULL) return ;

        if(res.size()==level) res.push_back(node->val);
        recursion(node->left,level+1,res);
        recursion(node->right,level+1,res);
    }
};