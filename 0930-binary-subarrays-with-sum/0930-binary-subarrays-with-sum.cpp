class Solution {
public:

    int atMost(vector<int>& nums, int goal) {

        if (goal < 0) return 0;

        int l = 0;
        int sum = 0;
        int ans = 0;

        for (int r = 0; r < nums.size(); r++) {

            sum += nums[r];

            // shrink window until sum <= goal
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            // count valid subarrays ending at r
            ans += (r - l + 1);
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};