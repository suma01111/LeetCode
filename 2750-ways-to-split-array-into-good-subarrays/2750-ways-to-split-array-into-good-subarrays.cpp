class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        
        const int MOD = 1e9 + 7;

        // We start with 1 because we'll keep multiplying the number of choices.
        long long ans = 1;

        int prevOne = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 1) {

                // If this is NOT the first 1
                if (prevOne != -1) {
                    ans = (ans * (i - prevOne)) % MOD;
                }
                prevOne = i;// Update the position of the current 1
            }
        }

        return prevOne == -1 ? 0 : ans;
    }
};

 // ans = (ans * (i - prevOne)) % MOD;
// Distance between consecutive 1's
                    // Example:
                    // 1 0 0 1
                    // prevOne = 0, i = 3
                    // distance = 3
                    //
                    // There are exactly 3 possible places
                    // to split between these two 1's.
                  