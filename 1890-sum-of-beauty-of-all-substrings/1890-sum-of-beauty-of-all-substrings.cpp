class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> MapFreq;
            
            for (int j = i; j < s.size(); j++) {
                MapFreq[s[j]]++;  // build freq map for substring s[i..j]
                
                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;

                for (auto it : MapFreq) {
                    maxFreq = max(maxFreq, it.second);
                    minFreq = min(minFreq, it.second);
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};

/* EXAMPLE 

1. "aab" → freq: a=2, b=1
→ beauty = 2 - 1 = 1
2. "aabc" → a=2, b=1, c=1
→ beauty = 2 - 1 = 1
3. "aabcb" → a=2, b=2, c=1
→ beauty = 2 - 1 = 1

4. "abcb" → a=1, b=2, c=1
→ beauty = 2 - 1 = 1

5. "bcb" → b=2, c=1
→ beauty = 2 - 1 = 1

*/