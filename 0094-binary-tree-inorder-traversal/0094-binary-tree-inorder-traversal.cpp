/*
Approach (Morris Inorder Traversal)

1. Use the concept of threaded binary tree to perform inorder traversal.
2. No recursion and no stack are used, so extra space is O(1).
3. For every node:
   a) If left child is NULL:
      - Visit the current node.
      - Move to its right child.
   b) Otherwise:
      - Find its inorder predecessor (rightmost node in left subtree).
      - If predecessor's right is NULL:
            Create a temporary thread to current node.
            Move to left child.
      - Else (thread already exists):
            Remove the thread.
            Visit current node.
            Move to right child.

Time Complexity : O(N)
Space Complexity: O(1)
*/
class Solution {
public:
vector<int> inorderTraversal(TreeNode* root) {

    vector<int> ans;
    TreeNode* curr = root;

    while (curr != NULL) {
        // Case 1: No left subtree
        if (curr->left ==NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else {
            // Find inorder predecessor
            // (Rightmost node of left subtree)
            TreeNode* pred = curr->left;

            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (pred->right ==NULL) {
                pred->right = curr;// Create temporary thread back to curr node
                curr = curr->left;
            }
            else {
                // Left subtree already processed, Remove temporary thread
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}
};