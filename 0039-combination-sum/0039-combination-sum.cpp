class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combine;
        vector<vector<int>> ans;

        CS(candidates, 0, combine, ans, target );
        return ans;
    }

    void CS(vector<int>& candidates, int i, vector<int>&  combine, vector<vector<int>>& ans,int target){

        //base case
        if (target == 0) {
            ans.push_back(combine);
            return;
        }
        if (target < 0 || i == candidates.size()) {
            return;
        }


        //include
        combine.push_back(candidates[i]);
        CS(candidates, i, combine, ans, target-candidates[i]);//multiple and single both

        combine.pop_back();
        CS(candidates, i+1, combine, ans, target);
    }
};