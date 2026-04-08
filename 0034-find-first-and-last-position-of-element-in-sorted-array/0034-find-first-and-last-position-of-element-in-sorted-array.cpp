class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    
        vector<int> ans(2,-1);

        for(int k=0;k<nums.size();k++){
            if(nums[k]==target) {
                ans[0]=k;
                break;}
        }

        for(int k=nums.size()-1; k>=0;k--){
            if(nums[k]==target){
                ans[1]=k;
                break;
            }
        }

        return ans;
    }
};