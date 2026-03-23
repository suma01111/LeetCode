//sorting 
// Fix i  
// Fix j  
// Use two pointers (k, l)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end()); //sorting 

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; //removing duplicates(RP)

            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;//RP

                int k = j + 1;
                int l = n - 1;

                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k-1]) k++; //RP
                        while(k < l && nums[l] == nums[l+1]) l--;//RP
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};