//sol 2 , optimal 2 pointers
class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int freq[3]={0};
        int ans=0;

        for(int r=0;r<s.size();r++){
            freq[s[r]-'a']++;

            while(freq[0]>=1 &&  freq[1]>=1 && freq[2]>=1){
                ans += s.size()-r;// IMPORTANT
                freq[s[l] - 'a']--;   
                l++;
            }
        }
        return ans;
    }
};

/*
Current valid substring:

[0..2] = "abc"

Now if we extend the right end:

[0..3] = "abca"
[0..4] = "abcab"
[0..5] = "abcabc"

These are also valid because once a window contains a,b,c, adding more characters cannot remove them.
*/

/* BY MAP
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, r = 0;
        long long ans = 0;

        unordered_map<char, int> mp;

        while (r < n) {

            mp[s[r]]++;

            while (mp['a'] > 0 &&
                   mp['b'] > 0 &&
                   mp['c'] > 0) {

                ans += (n - r);

                mp[s[l]]--;
                l++;
            }

            r++;
        }

        return ans;
    }
};
*/