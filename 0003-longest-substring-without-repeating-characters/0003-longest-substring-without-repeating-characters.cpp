class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r=0; //left right window index
        int maxLen =0;
        unordered_map<char, int> mp;

        while(r<s.size()){
            if(mp.count(s[r])){ //r in map 
                l = max(l,mp[s[r]]+1);
            }
            mp[s[r]] = r;
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};