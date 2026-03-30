class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num : s) {
            // start only if it's the beginning of sequence
            if(s.find(num - 1) == s.end()) {
                int curr = num;
                int cnt = 1;

                while(s.find(curr + 1) != s.end()) {
                    curr++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};