class Solution {
public:

    int helper(vector<int>& A, vector<int>& B) {
        int ans = 0;
        for (long long x : A) {
            long long target = x * x;
            unordered_map<long long, int> mp;

            for (long long y : B) {
                if (target % y == 0) {
                    long long need = target / y;
                    if (mp.count(need))
                        ans += mp[need];
                }
                mp[y]++;
            }
        }

        return ans;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1, nums2) +
               helper(nums2, nums1);
    }
};