class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int psum=0;  // stores prefix sum remainder (prefixSum % k)
        
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            psum = (psum+nums[i])%k;
            if(m.find(psum)!=m.end()){
                if((i-m[psum])>1){
                    return true;
                }
            }
            else m[psum] = i;
        }
        return false;
    }
};