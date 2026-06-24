//more optimal then hashmap (little more)
//unordered_map → slower (hashing)
//Array → O(1) direct access, faster in practice

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, -1); // ASCII

        int l= 0;
        int maxLen =0;

        for(int r=0; r< s.size();r++) {
            if(freq[s[r]] != -1) {
                l=max(l, freq[s[r]] + 1); //IMPP
            }

            freq[s[r]]=r;
            maxLen =max(maxLen, r-l+1);
        }

        return maxLen;
    }
};

