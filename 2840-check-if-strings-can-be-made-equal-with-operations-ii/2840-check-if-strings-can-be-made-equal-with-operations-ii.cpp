//sub02 : arnab

class Solution{
public:
    bool checkStrings(string s1,string s2) {
        int n = s1.size(); 
        vector<int> cnt(26);

        for(int i=0;i<n;i+=2) cnt[s1[i]-'a']++;
        for(int i=0;i<n;i+=2) cnt[s2[i]-'a']--;

        for(auto x : cnt){
            if(x) return false;
        }

        for(int i=1;i<n;i+=2) cnt[s1[i]-'a']++;
        for(int i=1;i<n;i+=2) cnt[s2[i]-'a']--;

        for(auto x: cnt){
            if(x) return false;
        }
            
        return true;
    }
};