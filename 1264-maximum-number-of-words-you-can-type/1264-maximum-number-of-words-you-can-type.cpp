class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(),brokenLetters.end());
        int cnt =0; //word cnt , which dont contain brokenLetter words

        stringstream ss(text); //word into letters
        string word;

        while(ss>>word){
            bool ok = true;
            for(char c: word){
                if(broken.count(c)){
                    ok = false ;
                    break;
                }
            }
            if(ok) cnt++; 
        }
        return cnt;
    }
};