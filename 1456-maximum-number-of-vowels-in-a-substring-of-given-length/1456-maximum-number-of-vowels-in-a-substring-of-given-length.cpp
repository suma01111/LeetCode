class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    int maxVowels(string s, int k) {
        int cnt = 0;

        // count vowels in first window
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) cnt++;
        }

        int maxii = cnt;

        // slide the window
        for(int i = k; i < s.size(); i++){
            if(isVowel(s[i])) cnt++;      // add new char
            if(isVowel(s[i-k])) cnt--;    // remove old char

            maxii = max(maxii, cnt);
        }

        return maxii;
    }
};