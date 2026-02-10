class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int even =0,odd=0;
            unordered_set<int> sett;
            for(int j=i;j<nums.size();j++){
                if(sett.find(nums[j])==sett.end()){
                    sett.insert(nums[j]);
                    if(nums[j]%2==0) even++;
                    else odd++;
                }
                if(even==odd) ans = max(ans, j-i+1);
            }
            
        }
        return ans;
    }
};