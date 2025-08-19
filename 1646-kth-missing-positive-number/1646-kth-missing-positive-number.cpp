class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Binary search to find first index where missing >= k
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1); //IMP

            if (missing < k)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left + k;
    }
};
