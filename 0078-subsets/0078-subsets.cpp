class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

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

        // include
        curr.push_back(nums[i]);
        allSubsets(nums, curr, ans, i + 1);

        curr.pop_back(); // important

        // exclude
        allSubsets(nums, curr, ans, i + 1);
    }
};
