class Solution {
public:
    bool isAnagram(string s, string t) {
        //base case
        if(s.size() != t.size()) return false;

        vector<int> cnt(26,0) ; //cnt(size,value)

        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;   //counting letters in s
            cnt[t[i]-'a']--;   // minus ing letter cnt wrt t
        }

        for(int freq : cnt){
            if(freq!=0) return false;
        }
        return true;
    }
};