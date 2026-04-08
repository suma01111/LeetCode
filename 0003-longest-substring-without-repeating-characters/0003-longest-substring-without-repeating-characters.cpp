class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;

        int l=0, r=0;
        int maxLen=0;

        while(r < s.size()){
        if(m.find(s[r]) == m.end()){
            m[s[r]] = r;
        }
        else{
            l = max(l, m[s[r]] + 1);
            m[s[r]] = r;
        }
        
        maxLen = max(maxLen, r - l + 1); // Always update
        r++;
        }
        
        return maxLen;
    }
};