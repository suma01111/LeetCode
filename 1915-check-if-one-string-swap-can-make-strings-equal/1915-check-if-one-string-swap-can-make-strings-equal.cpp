class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true ;

        vector<char> mismatch ;
        int mismatchedIdx =0;
        int pos =0; //position work as pointer
        while (pos < s1.size()){
            if(s1[pos]!=s2[pos]){
                mismatch.push_back(s1[pos]);
                mismatch.push_back(s2[pos]);
                mismatchedIdx++;
            }
            if(mismatchedIdx>2) return false;
            pos++;
        }
        
        if (mismatch.size()==4) {
            return(mismatch[0]==mismatch[3] and mismatch[1]==mismatch[2]);
        }
        return false;
    }
};