class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<int,int> m1; //char , freq
        unordered_map<int,int> m2;

        for(int i=0;i<s1.size();i=i+2){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }

        bool even = false;
        if(m1==m2) even = true;


        if(even){
            for(int i=1;i<s1.size();i+=2){
                m1[s1[i]]++;
                m2[s2[i]]++;
            }
            if(m1==m2) return true;
        }
        
        return false;
    }
};