class Solution {
public:
    bool isFreq(int freq1[], int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }


    vector<int> findAnagrams(string s, string p) {
        
        if(p.size()>s.size()) return {}; //base case

        int Pfreq[26] ={0};
        for(char c : p){
            Pfreq[c-'a']++;
        }

        vector<int> ans;
        //sliding window of p size 
        int j = 0;
        
         for(int i=0;i<=(s.size()-p.size());i++){
            j=i + p.size();
            int sFreq[26]={0};

            for(int k = i;k<j ;k++){
                sFreq[s[k] - 'a']++;
            }

            if(isFreq(sFreq, Pfreq))
                ans.push_back(i);
         }
         
        return ans;
        
    }
};