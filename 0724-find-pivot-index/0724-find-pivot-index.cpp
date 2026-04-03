//by me 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];

        for(int i=1;i<n;i++){
            prefix[i] = nums[i]+prefix[i-1];
        }

        int leftSum=0, rightSum=0;

        for(int i=0;i<n;i++){
            if(i>0) leftSum=prefix[i-1]; 
            if(i==0 || i<n)  rightSum = prefix[n-1]-prefix[i] ; 

            if(leftSum == rightSum) return i;
        }

        return -1;
    }
};