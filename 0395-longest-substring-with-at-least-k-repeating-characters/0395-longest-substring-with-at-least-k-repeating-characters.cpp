class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;

        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {

            unordered_map<char, int> mp;
            int l = 0;

            int unique = 0;
            int countAtLeastK = 0;

            for (int r = 0; r < s.size(); r++) {
                mp[s[r]]++;

                if (mp[s[r]] == 1)
                    unique++;

                if (mp[s[r]] == k)
                    countAtLeastK++;

                while (unique > targetUnique) {
                    if (mp[s[l]] == k)
                        countAtLeastK--;

                    mp[s[l]]--;

                    if (mp[s[l]] == 0) {
                        mp.erase(s[l]);
                        unique--;
                    }

                    l++;
                }

                if (unique == targetUnique &&
                    countAtLeastK == targetUnique) {
                    ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};