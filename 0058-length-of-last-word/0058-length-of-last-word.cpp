class Solution {
    int cnt =0;
public:
    int lengthOfLastWord(string s) {
        for(int i=s.size()-1;i>=0;i--){
            if (s[i] == ' ' && cnt == 0) continue; // skip trailing spaces
            if (s[i] == ' ') break;               // stop at space before last word
            cnt++;
        }
        return cnt;
    }
};
