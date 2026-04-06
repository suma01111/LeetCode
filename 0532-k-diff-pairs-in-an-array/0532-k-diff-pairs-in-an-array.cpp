class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate i

            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicate j

                int diff = abs(nums[i] - nums[j]);
                if(diff == k) cnt++;
            }
        }
        return cnt;
    }
};