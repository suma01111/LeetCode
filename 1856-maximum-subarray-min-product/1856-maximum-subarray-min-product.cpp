class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1e9 + 7;

        // Prefix sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element (FIXED)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long subSum = prefix[right[i]] - prefix[left[i] + 1];
            ans = max(ans, subSum * nums[i]);
        }

        return ans % MOD;
    }
};
