class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] < nums[mid + 1])  l = mid + 1;   // go right
            else  h = mid;       // go left or stay
        }

        return l; // peak index
    }
};