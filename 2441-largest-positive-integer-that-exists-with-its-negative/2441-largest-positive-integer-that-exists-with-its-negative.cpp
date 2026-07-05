class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxi=-1;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi && m.find(-nums[i])!= m.end()){
                maxi=abs(nums[i]);
            }
        }

        return maxi;
    }
};