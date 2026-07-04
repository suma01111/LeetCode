/**
// 1. Perform postorder traversal.
// 2. Left returns (min,max,sum).
// 3. Right returns (min,max,sum).
// 4. Check BST condition.
// 5. If BST:
//      Update answer.
//      Return updated info.
// 6. Else:
//      Return invalid range.
 */

class NodeValue {
public:
    int minNode, maxNode, sum;

    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;
    NodeValue solve(TreeNode* root) {

        // Empty tree is a BST
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);

        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);

        // Current subtree is BST
        if (left.maxNode < root->val &&
            root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return NodeValue(
                min(left.minNode, root->val),
                max(right.maxNode, root->val),
                currSum
            );
        }

        // Invalid BST
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};