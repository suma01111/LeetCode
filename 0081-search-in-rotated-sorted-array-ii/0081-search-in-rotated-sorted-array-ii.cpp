class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right =nums.size()-1;

        while(left<=right){
            int mid=left + (right-left)/2 ;

            if(nums[mid]== target) return true;

            // Handle duplicates: If left, mid, and right are same,
            // we cannot determine which half is sorted ,shrink search space
            if(nums[left] == nums[mid] && nums[mid]== nums[right]){
                left++;
                right--;
            }

            // Check if left half is sorted
            else if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target <= nums[mid]){
                    right = mid-1;
                } else {
                    left = mid +1;
                }
            }

            //otherwise right half must be sorted
            else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

        }


        return false;
    }
};