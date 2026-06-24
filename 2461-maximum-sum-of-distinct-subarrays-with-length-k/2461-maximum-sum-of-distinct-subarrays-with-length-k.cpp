class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l=0;
        unordered_map<int,int> m;
        long long sum=0;
        long long ans=0;

        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            m[nums[r]]++;

            if(r-l+1 >k){ //m.size()>k
                sum-=nums[l];
                m[nums[l]]--;

                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }

            if(m.size()==k && r-l+1==k) ans=max(ans,sum);
        }

        return ans;
    }
};