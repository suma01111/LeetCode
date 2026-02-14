class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> result;

        for (int x : nums2) {
            if (s1.find(x) != s1.end()) //s.count(x)
                result.insert(x);
        }

        return vector<int>(result.begin(), result.end());
    }
};        