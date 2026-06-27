class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        return max(0, mx - mn - 2 * k);
    }
};

// Therefore the smallest possible score is (mx-k)-(mn+k)=mx-mn-2k
// If this becomes negative, we can make every element equal, so answer is 0.