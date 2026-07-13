class Solution {
public:
    // Approach:
    // 1. Use the string "123456789".
    // 2. Generate every possible substring.
    // 3. Convert the substring into an integer.
    // 4. If it lies in [low, high], add it to the answer.

    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;
        int minLen=to_string(low).size();
        int maxLen=to_string(high).size();

        // Length of sequential number
        for (int len=minLen;len<=maxLen;len++) {

            // Starting index
            for (int i=0;i+len<=9;i++) {
                int num=stoi(digits.substr(i,len));
                if (num>=low && num<=high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};