class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        int l=0;
        long long WSum=0;
        int ans=0;

        for(int r=0;r<n;r++){
            WSum += nums[r]; //windowsum
            // int len = r-l+1; dont predict beacuse window also shrinks

            while((long long)nums[r]*(r-l+1) - WSum > k){
                WSum -= nums[l];
                l++;
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};