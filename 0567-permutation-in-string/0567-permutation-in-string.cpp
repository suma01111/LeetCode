class Solution {
public:

//helper fn
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }        
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        //step1: store freq characters of s1 
        int freq[26] = {0};
        for(int i=0;i<s1.size();i++){
            freq[s1[i] - 'a']++ ;  //s1[i]-'a' gives index (0 to 25)
        }

        //step2: search s1 permutation in s2 using window 
        int windowSize = s1.length();

        for(int i=0;i<s2.length();i++){
            int winIdx = 0; // window index
            int originIdx =i; //original index
            int winFreq[26]={0}; //window freq record

            while(winIdx < windowSize && originIdx < s2.length()){
                winFreq[s2[originIdx] - 'a']++;
                winIdx++; originIdx++;
            }

            if(isFreqSame(freq, winFreq)){
                return true;
            }
        }
        return false;
    }
};