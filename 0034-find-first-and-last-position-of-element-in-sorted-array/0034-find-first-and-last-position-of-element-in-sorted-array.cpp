class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int l=0, h=nums.size()-1;
        int n=nums.size();

        int lb =n;
        while(l<=h){
            int mid= l+(h-l)/2;
            if(nums[mid]>=target){
                lb = mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return lb;
    }


public:
    int upperBound(vector<int>& nums, int target){
        int l=0, h=nums.size()-1;
        int n=nums.size();

        int ub =n;
        while(l<=h){
            int mid= l+(h-l)/2;
            if(nums[mid]>target){
                ub = mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ub;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int LB = lowerBound(nums,target);
        if(LB==nums.size() || nums[LB]!= target) return {-1,-1};

        int UB = upperBound(nums,target) - 1;

        return {LB,UB};

    }
};