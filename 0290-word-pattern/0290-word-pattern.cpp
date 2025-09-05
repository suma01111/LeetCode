class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string> Words; //to store separated words of s string
        string word; //temp string word to denote each word of string vector words

        while(iss >> word){
            Words.push_back(word);
        }

        //Base case
        if (Words.size() != pattern.size()) return false;

        unordered_map<char,string> p2w;
        unordered_map<string,char> w2p;

        for(int i=0;i<pattern.size();i++){
            char c = pattern[i];
            string w = Words[i];

            if(p2w.count(c) && p2w[c]!= w) return false ;
            if(w2p.count(w) && w2p[w]!= c) return false ;

            p2w[c] = w;            
            w2p[w] = c;            

        }
        return true;
    }
};







