class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sumLevel = 0;
            level++;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sumLevel += node->val; //IMP
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            } //since we pushed L and R, again loop start from i=0 

            if (maxSum < sumLevel) { //update after every level
                maxSum = sumLevel;
                ans = level;  
            }
        }
        return ans;
    }
};