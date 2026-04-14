class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        int minii =INT_MAX;

        for(int i=0;i<nums1.size();i++) m[nums1[i]]++;

        for(int i=0;i<nums2.size();i++){
            if(m.find(nums2[i]) != m.end()){
                minii= min(minii,nums2[i]);
            }
        }

        if(minii == INT_MAX) return -1;
        return minii;
    }
};