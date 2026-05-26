class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_map<char,int> m;

        // store ascii values
        for(char ch : word){
            m[ch] = ch;
        }

        int cnt = 0;

        for(auto it : m){

            // check only lowercase letters
            if(it.first >= 'a' && it.first <= 'z'){

                // if uppercase exists
                if(m.find(it.first - 32) != m.end()){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};