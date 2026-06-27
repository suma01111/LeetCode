class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        mp[0] = -1;   // prefix sum 0 before array starts

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) sum += 1;
            else sum -= 1;

            if (mp.count(sum)) ans = max(ans, i - mp[sum]);
            else mp[sum] = i;   // store first occurrence
        }

        return ans;
    }
};