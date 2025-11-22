class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;

        for (int v : nums) {
            int r = v % 3;          // remainder
            ops += min(r, 3 - r);   // cost to make divisible by 3
        }

        return ops;
    }
};
