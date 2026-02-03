class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int p=0;
        // 1st phase: strictly increasing
        while(p<n-2 && nums[p]<nums[p+1]) p++;
        
        if(p==0) return false; //check by a base case

        int q=p;
        // 2nd phase: strictly decreasing
        while(q<n-1 && nums[q]>nums[q+1]) q++;

        if(p==q || q==n-1) return false; //again check by a base case

        // 3rd phase: strictly increasing
        while(q<n-1 && nums[q]<nums[q+1]) q++;

        return q==n-1;
    }
};

