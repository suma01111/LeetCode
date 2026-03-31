class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // step 1: check validity
        if(str1 + str2 != str2 + str1) return "";

        // step 2: find gcd of lengths
        int len = gcd(str1.size(), str2.size());

        // step 3: return prefix
        return str1.substr(0, len);
    }
};