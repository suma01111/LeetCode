/**
USING ITERATIVE 1 STACKS
Approach : trickyy little
Keep pushing all left nodes.
When curr == NULL, look at the top node.
If the top node has an unvisited right child, move to the right subtree.
Otherwise, visit the node, pop it, and mark it as lastVisited.
Repeat until both curr == NULL and stack is empty.
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;// Last node whose value was added to ans

        while(curr != nullptr || !st.empty()) {
            if(curr != nullptr) {//traverse all Left node
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* node = st.top();//(don't pop yet)

                // If right subtree exists and is not processed,
                // traverse the right subtree first.
                if(node->right != nullptr && lastVisited != node->right) {
                    curr = node->right;
                }
                else {
                     // Left subtree is done.
                    // Right subtree is either NULL or already processed.
                    // Now process the current node.
                    ans.push_back(node->val);

                    // Mark this node as processed
                    lastVisited = node;

                    // Remove it from stack
                    st.pop();
                }
            }
        }

        return ans;
    }
};