class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freqMag[26] ={0};
        for(int i=0;i<magazine.size();i++){
            freqMag[magazine[i]-'a']++;
        }

        
        for(char ch : ransomNote){
            freqMag[ch - 'a'] --;
            if(freqMag[ch-'a']<0) return false;
        }

        return true;
    }
};