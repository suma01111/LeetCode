class Solution {
    int digit(int n){
        int cnt=0;
        while(n>0){
            int dig = n%10;
            cnt++;
            n=n/10;
        } 
        return cnt; 
    }

public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int count = digit(nums[i]);
            if(count%2==0) ans++;
        }
        return ans;
    }
};