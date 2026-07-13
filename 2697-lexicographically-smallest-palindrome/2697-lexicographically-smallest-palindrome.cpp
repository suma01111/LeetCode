class Solution {
public:
    // Approach:
    // 1. Use two pointers from both ends.
    // 2. If characters are equal, move inward.
    // 3. Otherwise, one change is necessary.
    // 4. Replace the larger character with the smaller one
    //    to obtain the lexicographically smallest palindrome.

    string makeSmallestPalindrome(string s) {
        int i=0;
        int j=s.size()-1;

        while (i<j) {
            if (s[i]!=s[j]) {
                // Keep the smaller character
                if (s[i]<s[j])
                    s[j]=s[i];
                else
                    s[i]=s[j];
            }
            i++;
            j--;
        }

        return s;
    }
};