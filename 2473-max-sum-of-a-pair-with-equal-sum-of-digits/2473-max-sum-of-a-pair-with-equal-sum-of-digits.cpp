class Solution {
    private: 
    int getDigitSum(int val){
        int sum =0;
        while(val){
            sum += val%10;
            val = val/10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int max_sum = -1;
        unordered_map<int, int> digitSum_Maxvalnum;  // Stores max value for each digit sum
        
        for (int ele : nums) {
            int digitSum = getDigitSum(ele);
            
            if (digitSum_Maxvalnum.count(digitSum)) {
                max_sum = max(max_sum, ele + digitSum_Maxvalnum[digitSum]); 
                
                // Ensure max element is stored in the map
                if (digitSum_Maxvalnum[digitSum] < ele)
                    digitSum_Maxvalnum[digitSum] = ele;
            } else {
                digitSum_Maxvalnum[digitSum] = ele;
            }
        }
        return max_sum;
    }
};