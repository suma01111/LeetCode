class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++; //char is key 
            if(m[s[i]]==2) return s[i];
        }
        
        return -1;
    }
};