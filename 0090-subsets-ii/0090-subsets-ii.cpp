class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());   // IMPORTANT
        allSubsets(nums, curr, ans, 0);
        return ans;
    }

    void allSubsets(vector<int>& nums, vector<int>& curr,
                    vector<vector<int>>& ans, int i) {

        // base case
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // INCLUDE nums[i]
        curr.push_back(nums[i]);
        allSubsets(nums, curr, ans, i + 1);
        
        curr.pop_back();

        // EXCLUDE nums[i]
        // skip all duplicates of nums[i]
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        allSubsets(nums, curr, ans, i + 1);
    }
};
