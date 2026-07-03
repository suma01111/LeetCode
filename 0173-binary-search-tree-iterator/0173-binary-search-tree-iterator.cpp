/**
Push all left nodes in actual stack
// next() =>  Pop top.
// Move to right child.
// Push all left nodes of right child.
// Return popped value.

// hasNext()
// Stack empty ? false : true
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;

    void storeLeftNodes(TreeNode* root){ //IMPP, store left nodes
        while(root!=NULL){
            st.push(root) ;
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() { //IMP
        TreeNode* ans = st.top();
        st.pop();
        if(ans->right) storeLeftNodes(ans->right); //IMPP
        return ans->val;
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */