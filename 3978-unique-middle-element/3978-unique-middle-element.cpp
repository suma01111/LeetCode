class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int n=nums.size();
        int x = nums[n/2];
        if(m[x]>1) return false;

        return true;
    }
};