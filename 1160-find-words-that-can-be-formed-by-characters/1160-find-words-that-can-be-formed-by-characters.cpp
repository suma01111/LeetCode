class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26] = {0};

        // count chars frequency
        for(char c : chars)
            freq[c - 'a']++;

        int ans = 0;

        // check each word, IMPPP
        for(string word : words) {
            int temp[26] = {0};
            bool ok = true;

            for(char c : word) {
                temp[c - 'a']++; //get index then update freq
                if(temp[c - 'a'] > freq[c - 'a']) { //exclude all <= cases
                    ok = false;
                    break;
                }
            }

            if(ok)
                ans += word.length();
        }

        return ans;
    }
};
