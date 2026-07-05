
class Solution {
public:
    long long maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();

        long long ans=0;
        long long mx=nums[0];

        for (int j=k;j<n;j++) {
            mx=max(mx, 1LL*nums[j-k]);
            ans=max(ans, mx+nums[j]);
        }

        return ans;
    }
};