class Solution {
public:

    int atMost(vector<int>& nums, int k) {
        int l=0;
        int ans=0;

        for (int r=0;r<nums.size();r++) {

            // Count odd numbers in window
            if (nums[r] % 2)
                k--;

            // Shrink if odds exceed limit
            while (k < 0) {
                if (nums[l] % 2)
                    k++;
                l++;
            }

            // Number of valid subarrays ending at r
            ans += (r - l + 1);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};