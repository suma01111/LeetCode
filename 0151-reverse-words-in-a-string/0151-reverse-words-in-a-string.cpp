class Solution {
public:
//firstly reverse whole string then 
//then reverse indiviual string , take care of spaces

    string reverseWords(string s) {
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue; 

            string word = "";

            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if (!ans.empty()) ans += " "; // add space before appending next word
            ans += word;
        }

        return ans;
    }
};
