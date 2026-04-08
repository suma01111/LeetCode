//more optimal then hashmap (little more)
//unordered_map → slower (hashing)
//Array → O(1) direct access, faster in practice

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // ASCII

        int l = 0;
        int maxLen = 0;

        for(int r = 0; r < s.size(); r++) {
            if(lastIndex[s[r]] != -1) {
                l = max(l, lastIndex[s[r]] + 1);
            }

            lastIndex[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

