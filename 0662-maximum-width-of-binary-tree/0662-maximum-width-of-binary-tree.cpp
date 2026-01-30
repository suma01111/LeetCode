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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q; //{node, index}
        q.push({root, 0});

        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second; //IMP
            long long end = q.back().second; //IMP

            maxWidth = max(maxWidth, (int)(end - start + 1)); //IMPP

            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                long long idx = curr.second - start; //normalization

                if (curr.first->left)
                    q.push({curr.first->left, 2 * idx + 1});

                if (curr.first->right)
                    q.push({curr.first->right, 2 * idx + 2});
            }
        }
        return maxWidth;
    }
};


