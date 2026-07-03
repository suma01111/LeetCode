/**
// 1. Store inorder traversal.
// 2. Apply two pointers.
// 3. If sum == k return true.
// 4. If sum < k move left pointer.
// 5. Else move right pointer.
 */
class Solution {
    unordered_set<int> set; 
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false; 

        if(set.count(k - root->val)) return true; // Check if complement exists
        
        set.insert(root->val);// Insert current value

        return findTarget(root->left,k)
            || findTarget(root->right,k);
    }
};