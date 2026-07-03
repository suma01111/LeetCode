/** sol 2
// 1. Store inorder traversal.
// 2. Apply two pointers.
// 3. If sum == k return true.
// 4. If sum < k move left pointer.
// 5. Else move right pointer.
 */
class Solution {
public:
    vector<int> inorder;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root); //give update inorder array

        int i=0, j=inorder.size()-1;
        while (i < j) {
            int sum = inorder[i]+inorder[j];

            if (sum == k) return true;
            if (sum < k) i++;
            else j--;
        }

        return false;
    }
};

// Time: O(N)
// Space: O(N)