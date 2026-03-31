class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string res ;

        while(i<word1.size() && j<word2.size()){
            //cout<<"x";
            res.push_back(word1[i]);
            i++;
            res.push_back(word2[j]);
            j++;
        }

        //remaining
        while(i<word1.size()) {
            //cout<<"i";
            res.push_back(word1[i]); i++;
        }

        //remaining
        while(j<word2.size()) {
            //cout<<"j";
            res.push_back(word2[j]); j++;
        }

        return res;
    }
};