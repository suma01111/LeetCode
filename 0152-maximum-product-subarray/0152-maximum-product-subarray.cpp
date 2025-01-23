class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;

        int prefix =1;
        for(int i=0;i<nums.size();i++){
            prefix *= nums[i];
            if(prefix > maxProd) maxProd = prefix;
             if (prefix == 0) prefix = 1; 
        }

        int suffix =1;
        for(int i=nums.size()-1;i>=0;i--){
            suffix *= nums[i];
            if(suffix > maxProd) maxProd = suffix;
            if (suffix == 0) suffix = 1;
        }
        return maxProd;
    }
};