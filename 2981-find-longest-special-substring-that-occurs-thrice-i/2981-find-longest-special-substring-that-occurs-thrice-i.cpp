// Approach
// Iterate len from n to 1.
// For every starting index:
// Check whether the substring contains only one character.
// If yes, store its frequency.
// If any frequency reaches 3, return len.
// Otherwise return -1.

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        // Try lengths from largest to smallest
        for (int len = n; len >= 1; len--) {
            unordered_map<string, int> mp;
            for (int i = 0; i + len <= n; i++) {
                bool special = true;
                for (int j = i + 1; j < i + len; j++) {
                    if (s[j] != s[i]) {
                        special = false;
                        break;
                    }
                }
                if (special) {
                    string sub = s.substr(i, len);
                    mp[sub]++;

                    if (mp[sub] >= 3)
                        return len;
                }
            }
        }

        return -1;
    }
};