class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
            for(int j = 0;j<nums.size();j++){
                if(abs(i-j)<=k){
                    res.push_back(j);
                    
                }
            }
            }
        }
        // Remove duplicates and sort
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};