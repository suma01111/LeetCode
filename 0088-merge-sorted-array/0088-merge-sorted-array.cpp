class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Pointer for the last element in the initial part of nums1
        int j = n - 1;  // Pointer for the last element in nums2
        int k = m + n - 1;  // Pointer for the last position in nums1 where elements will be merged

        // Compare elements from the end of nums1 and nums2 and place the larger one at the end of nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        // If there are remaining elements in nums2, copy them to nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
