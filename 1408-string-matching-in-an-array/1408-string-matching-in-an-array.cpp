// Approach: Compare Every Pair of Strings

// Since:n ≤ 100
// Maximum string length = 30
// We can simply compare every pair of strings.

// For each word:
// Check if it is a substring of any other word.
// If yes, add it to the answer and stop checking further.

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                if (words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};