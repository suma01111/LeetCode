class Solution {
public:
    int findLHS(vector<int>& nums) {
        int j = 0;
        int maxLen = 0;

        sort(nums.begin(), nums.end());  // ✅ Fix #1

        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] - nums[j] > 1) {  // ✅ Fix #2
                j++;
            }
            if (nums[i] - nums[j] == 1) {
                maxLen = max(maxLen, i - j + 1);
            }
        }
        return maxLen;
    }
};
