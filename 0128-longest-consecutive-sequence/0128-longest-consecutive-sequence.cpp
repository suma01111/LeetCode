class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());   // important

        int cnt = 1, maxi = 1;

        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i] == nums[i-1] + 1){
                cnt++;
            }
            else if(nums[i] != nums[i-1]){   // handle duplicates
                cnt = 1;
            }
            
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};