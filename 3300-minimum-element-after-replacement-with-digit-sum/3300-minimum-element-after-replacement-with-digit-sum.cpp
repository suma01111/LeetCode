class Solution {
public:
    int summ(int num, int sum){
        while(num>0){
             int dig=num%10;
            sum+=dig;
            num = num/10;
        }

        return sum;
    }


    int minElement(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            res.push_back(summ(nums[i],0));
            //cout<<res[i];
        }

        int minii=INT_MAX;
        for(int i=0;i<res.size();i++){
            if(res[i]<minii){
                minii= res[i];
            }
        }

        return minii;
    }
};