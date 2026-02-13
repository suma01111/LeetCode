class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int startingPosition = -1, endingPosition = -1;
        vector<int> ans(2,-1);
        for(int i=0 ; i<n ; i++){
            if(nums[i]==target){
                startingPosition = i;
                ans[0]=i;
                break;
            } 
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                endingPosition = i;
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};