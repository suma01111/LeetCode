class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m; //{nums,index}
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) != m.end()){
                if(abs(i-m[nums[i]]) <=k ) {
                    return true;
                    }
            }
            m[nums[i]] = i;  // update last index
        }
        return false;
    }
};