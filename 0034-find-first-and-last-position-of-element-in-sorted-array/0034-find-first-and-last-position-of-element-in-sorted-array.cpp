class Solution {

    //lower Bound, then check lb also
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

    //Upper bound
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

    //main function
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int LB = lowerBound(nums,target);
        if(LB==nums.size() || nums[LB]!= target) return {-1,-1}; //IMP CHECK

        int UB = upperBound(nums,target) - 1; //IMPP

        return {LB,UB};

    }
};

//if tera lb = n-1 (last elemet bhi h ) , no need to check ub cond because it will bw automaticall UB=ub-1 (ex: 5,7,7,8,8,10 ; target = 10)
