class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx =-1;

        //step1: find breaking pt, mark idx
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }

        //base case, all nums are in decreasing order so restart
        if(idx==-1){
            reverse(nums.begin(),nums.end()); 
            return;
            
        }

        //step2 : get someone > nums[idx] but the smallest one , and SWAP
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        //step3: reverse idx+1 -> n 
        reverse(nums.begin()+idx+1 , nums.end());
    }
};