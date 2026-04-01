class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int zeroCnt=0;
        int maxLen = INT_MIN;

        for(int r=0;r<nums.size();r++){

            if(nums[r]==0) zeroCnt++;

            //shrink window
            while(zeroCnt>k){
                if(nums[l]==0) zeroCnt--;
                l++;
            }

            // update max length
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};