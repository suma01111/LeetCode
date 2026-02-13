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
                ans += s.size()-r;
                freq[s[l] - 'a']--;   // IMPORTANT
                l++;
            }
        }
        return ans;
    }
};