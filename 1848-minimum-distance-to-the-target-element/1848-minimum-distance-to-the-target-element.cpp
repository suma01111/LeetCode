class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minii = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                int ans= abs(i-start);
                minii=min(minii,ans);
            }
        }
        return minii;
    }
};