class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff = INT_MIN;
        int Maxdiff = INT_MIN;
        for(int i=1;i<nums.size();i++){
            diff = abs(nums[i-1] - nums[i]);  // take absolute difference
            if(diff>Maxdiff) Maxdiff=diff;
        }
        int edgeDiff = abs(nums[nums.size() - 1] - nums[0]);
        if(edgeDiff > Maxdiff) Maxdiff = edgeDiff;


        return Maxdiff;
    }
};