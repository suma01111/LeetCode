/**
USING ITERATIVE INORDER USING STACK
first push all leftmost node , when no left node exit then
pop top , pb to ans vector
then node = node->right
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(node!=nullptr || !st.empty()) {
            while(node != nullptr) { //rem
                st.push(node);
                node = node->left;
            }

            node = st.top();//rem
            st.pop();

            inorder.push_back(node->val);
            node = node->right; //rem
        }

        return inorder;
    }
};