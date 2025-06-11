class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int MissingNum;
        int Sum = n*(n+1)/2;
        for(int i=0;i<n;i++){
            Sum= Sum - nums[i];
        }
        return Sum;
    }
};