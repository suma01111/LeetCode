class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            int leftSum=0,rightSum=0;
            for(int j=0;j<=i;j++) leftSum+=nums[j];
            for(int k = i + 1; k < nums.size(); k++) rightSum+=nums[k];
            int temp=leftSum-rightSum;
            if(temp%2==0) cnt++;
        }

        return cnt;
    }
};