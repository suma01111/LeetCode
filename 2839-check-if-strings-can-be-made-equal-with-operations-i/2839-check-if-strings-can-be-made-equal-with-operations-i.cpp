class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string res="";
        int n = s1.size();

        if(s1.size() != s2.size()) return false;
        
        for(int i=0;i<s2.size();i++){
            if(s1[i] != s2[i] && (i+2)<n){
                swap(s2[i], s2[i+2]);
            }
        }

        for(int i=0;i<s2.size();i++){
            if(s1==s2) return true;
        }

        return false;
    }
};