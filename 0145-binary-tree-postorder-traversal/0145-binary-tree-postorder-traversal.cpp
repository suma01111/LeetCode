/**
USING ITERATIVE 2 STACKS
in Stack1 =>> push node , pop(top node) and push its childer in st1 same
in Stack2 =>> that pop node from st1 will be pushed here 
after all traversal , st_1 will be empty and St_2 will be our ans of POSTORDER
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == nullptr) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop(); //pop top from st1
            st2.push(node);//push that node in st2

            //push node children in st1
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }

        //our final postOrder will be in st2
        while(!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};