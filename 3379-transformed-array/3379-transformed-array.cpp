class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j = 0;
            //case for +ve value
            if(nums[i]>0) {
                j = (i+nums[i]) % n;
                ans.push_back(nums[j]);
            }
            //case of negative
            else {
                j = ((i + nums[i]) % n + n) % n;
                ans.push_back(nums[j]);
            }
        }
        return ans;
        
    }
};