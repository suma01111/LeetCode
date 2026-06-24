class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt=1, maxLen=1;

        for(int i=1;i<s.size();i++){
            if(s[i]-'a'== ((s[i-1]-'a')+1)){
                cnt++;
                maxLen=max(maxLen, cnt);
            }
            else cnt=1;
        }

        return maxLen;
    }
};