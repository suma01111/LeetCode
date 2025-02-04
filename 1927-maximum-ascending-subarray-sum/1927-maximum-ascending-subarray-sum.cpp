class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum =nums[0];
        int curr_sum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                curr_sum += nums[i];
            }
            else{
             max_sum = max(max_sum,curr_sum);
             curr_sum = nums[i];
             }
        }
        return max(max_sum,curr_sum);
    }
};