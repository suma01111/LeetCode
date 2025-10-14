class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Function to check if a subarray is strictly increasing
        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; i++) {
                if (nums[i] >= nums[i + 1]) return false;  // not strictly increasing
            }
            return true;
        };

        // Check all possible pairs of adjacent subarrays
        for (int i = 0; i + 2 * k <= n; i++) {
            bool first = isIncreasing(i);
            bool second = isIncreasing(i + k);
            if (first && second)
                return true; // found two adjacent increasing subarrays
        }

        return false;
    }
};