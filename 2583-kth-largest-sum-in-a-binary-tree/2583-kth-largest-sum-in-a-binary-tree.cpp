/**
// 1. Perform level order traversal.
// 2. Compute sum of every level.
// 3. Store all sums.
// 4. If levels < k return -1.
// 5. Sort in descending order.
// 6. Return kth largest.
 */

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {

        vector<long long> sums;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
            sums.push_back(sum);
        }

        if (sums.size() < k) return -1;

        sort(sums.begin(),sums.end(),greater<long long>());

        return sums[k - 1];
    }
};