// Split s1 into words and store their frequencies in a map.
// Split s2 into words and update the same map.
// Any word with frequency exactly 1 is uncommon.
// Return all such words.
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        stringstream ss1(s1), ss2(s2);//IMPPP
        string word;

        while (ss1 >> word)
            mp[word]++;

        while (ss2 >> word)
            mp[word]++;

        vector<string> ans;

        for (auto it : mp) {
            if (it.second == 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};