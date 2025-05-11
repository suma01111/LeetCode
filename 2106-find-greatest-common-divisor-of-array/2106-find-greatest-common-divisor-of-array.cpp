class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int gcd=1;
        sort(nums.begin(),nums.end());
        int minEle = nums[0];
        int maxEle = nums[n-1];
        
        for(int i =1;i<=minEle;i++){
            if(minEle%i==0 && maxEle%i==0){
                gcd = i;
            }
        }
        return gcd;
    }
};