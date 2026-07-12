class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> sortArr(arr.begin(), arr.end());
        sort(sortArr.begin(), sortArr.end());

        unordered_map<int, int> m;
        int rank = 1;

        // Assign rank only to unique elements
        for (int x : sortArr) {
            if (m.find(x) == m.end())
                m[x] = rank++;
        }

        vector<int> ans;

        for (int x : arr)
            ans.push_back(m[x]);

        return ans;
    }
};