/** sol 3
Approach 2 (Optimal - 2 BST Iterators) ⭐
// 1. Create one iterator for inorder (smallest → largest).
// 2. Create one iterator for reverse inorder (largest → smallest).
// 3. Get the smallest and largest values.
// 4. If sum == k, return true.
// 5. If sum < k, move the left iterator.
// 6. If sum > k, move the right iterator.
// 7. Stop when both iterators meet.
 */

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse; //REM

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse; //IMP , remember
        pushAll(root);
    }

    // Push all left nodes (normal) or right nodes (reverse)
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

    // Return next smallest or next largest value
    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (reverse)
            pushAll(node->left);
        else
            pushAll(node->right);

        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        // Left iterator -> Inorder
        BSTIterator left(root, false);

        // Right iterator -> Reverse Inorder
        BSTIterator right(root, true);

        int i = left.next();     // Smallest value
        int j = right.next();    // Largest value

        while (i < j) {
            int sum = i + j;

            if (sum == k)
                return true;
            if (sum < k)
                i = left.next();     // Need larger value
            else
                j = right.next();    // Need smaller value
        }

        return false;
    }
};

// BST Iterator
// Time: O(N) (overall)
// Space: O(H)*2