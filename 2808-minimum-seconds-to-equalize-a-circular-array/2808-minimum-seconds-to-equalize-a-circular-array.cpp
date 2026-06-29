class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;//nums[i], {all idx where it occur}
        int n=nums.size();

        for (int i=0;i<n;i++)
            mp[nums[i]].push_back(i);

        int ans=INT_MAX;

        for (auto it:mp) {
            vector<int> pos=it.second;

            int maxGap=0;

            for (int i=1;i<pos.size();i++)
                maxGap= max(maxGap,pos[i]-pos[i-1]); //gap in normal arr

            maxGap= max(maxGap,pos[0]+n-pos.back());//gap in circulae arr

            ans= min(ans,maxGap/2);
        }

        return ans;
    }
};
// Approach
// Store all indices of every value.
// For each value:
// Find the maximum gap between consecutive indices.
// Find the circular gap:first + n - last
// Required time = maxGap / 2.
// Return the minimum time among all values.