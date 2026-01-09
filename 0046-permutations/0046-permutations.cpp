class Solution {
public:

    void getPermute(vector<int> &nums, int idx,vector<vector<int>> &ans){
        //base case, one permutation formed
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            getPermute(nums, idx+1,ans);
            //backtrack
            swap(nums[idx], nums[i]); //from this we reach to one level upper from bottom
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        getPermute(nums,0,ans );
        return ans;
    }
};