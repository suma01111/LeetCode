class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int closetSum = nums[0] + nums[1] + nums[2]; // FIX

        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];

                if(abs(target-sum) < abs(target-closetSum)) closetSum=sum; //IMP

                if(sum<target){
                    j++;
                }
                else{
                    k--;
                }

            }
        }
        return closetSum;
    }
};