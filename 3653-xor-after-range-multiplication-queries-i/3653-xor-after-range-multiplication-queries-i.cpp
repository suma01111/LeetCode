
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;

        // Process each query
        for (auto &q : queries) {
            int li = q[0];
            int ri = q[1];
            int ki = q[2];
            long long vi = q[3];

            // Apply updates
            for (int idx = li; idx <= ri; idx += ki) {
                nums[idx] = (nums[idx] * vi) % MOD;
            }
        }

        // Compute XOR of final array
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};