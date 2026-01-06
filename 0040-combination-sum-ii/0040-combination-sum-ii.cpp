class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combine;
        vector<vector<int>> ans;

        //sort
        sort(candidates.begin(), candidates.end()); 

        CS(candidates, 0, combine, ans, target);
        return ans;
    }

    void CS(vector<int>& candidates, int i, vector<int>& combine,           vector<vector<int>>& ans,int target) {

        if (target == 0) {
            ans.push_back(combine);
            return;
        }

        if (target < 0 || i == candidates.size()) return;

        // include (single use)
        combine.push_back(candidates[i]);
        CS(candidates, i + 1, combine, ans, target - candidates[i]);
        combine.pop_back();

        //skip duplicates
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        // exclude
        CS(candidates, i + 1, combine, ans, target);
    }
};
