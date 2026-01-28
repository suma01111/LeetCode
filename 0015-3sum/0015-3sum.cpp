class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //sorting the array
        sort(nums.begin(),nums.end());
        
        for(int i =0;i<nums.size();i++){
            // Avoid duplicates for the first element
            if(i>0 && nums[i]==nums[i-1]) continue;//skip

            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];

                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{ //sum==0
                result.push_back({nums[i],nums[j],nums[k]});

                //for further pairs 
                
                // Move j pointer and avoid duplicates
                while (j < k && nums[j] == nums[j + 1]) j++;
                // Move k pointer and avoid duplicates
                while (j < k && nums[k] == nums[k - 1]) k--;
                
                j++;
                k--;
                }
            }
        }
        return result;
    }
    
};