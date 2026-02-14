class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++) 
            m[nums[i]] = i; //(nums[i], idex(i))

        for(int i =0;i<nums.size();i++){
            int comp = target-nums[i]; //complement
            if(m.find(comp)!= m.end() && m[comp]!=i){
                return {i,m[comp]};
            }
        }
        return {};
    }
};