class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        //step1: find min abs diff
        for(int i=1;i<arr.size();i++){
            minDiff = min(minDiff, (arr[i]-arr[i-1]));
        }

        vector<vector<int>> result;

        //step2: collect pairs with min diff
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==minDiff){
                result.push_back({arr[i-1],arr[i]});
            }
        }
        return result;
    }
};