class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long sumAsc= 1LL*nums[0];
        long sumDsc= 1LL*nums[n-1];

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) {
                sumAsc+= 1LL*nums[i]; cout<<nums[i];
            }
            else {
                sumDsc+=1LL*nums[i-1];
                cout<<endl<<nums[i-1];
            }
        }

        if(sumAsc > sumDsc) return 0;
        else if(sumAsc < sumDsc) return 1;

        return -1;
    }
};