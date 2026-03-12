class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =nums.size();
        vector<int> pos;
        vector<int> neg;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        vector<int> ans;
        ans.push_back(pos[0]);
        int j=1,z=0;

        for(int i=1;i<nums.size();i++){
            if(i%2==0) {
                ans.push_back(pos[j]);
                j++;}
            else {
                ans.push_back(neg[z]);
                z++;
            }
        }
        return ans;
    }
};