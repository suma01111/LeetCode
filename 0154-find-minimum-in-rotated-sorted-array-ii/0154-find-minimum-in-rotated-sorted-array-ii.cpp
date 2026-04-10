class Solution {
public:
    int findMin(vector<int>& nums) {
        int minii = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<minii) minii=nums[i];
        }
        return minii;
    }
};