class Solution {
public:
    int search(vector<int>& nums, int target) {
         int l=0;
        int h = nums.size()-1;

        while(l<=h){
            int m = (l+h)/2;
            if(target==nums[m]){
                return m;
            }
             
        //checking is left side from mid is sorted?
        if(nums[l]<=nums[m]){
            if(nums[l]<=target && target<=nums[m]){
                h=m-1;
            }
            else l=m+1;
        }

        //checking is right is sorted
        if(nums[m]<=nums[h]){
            if(target>=nums[m] && nums[h]>=target){
                l=m+1;
            }
            else h=m-1;
        }
        
    }

    
    return -1;
    }
};