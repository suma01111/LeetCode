class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(k>nums.size()) return 0;

        double WindowSum =0;
        //first window
        for(int i=0;i<k;i++){
            WindowSum += nums[i];
        }

        double maxSum = WindowSum;
        //next windowss
        for(int i=k;i<nums.size();i++){
            WindowSum += nums[i];
            WindowSum -= nums[i-k];
            
            maxSum = max(maxSum, WindowSum);

        }
        return maxSum/k ;
    }
};