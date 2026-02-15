class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i--] - '0';
                }
            if (j >= 0) {
                sum += b[j--] - '0';
                }
            
            result.push_back(sum % 2 + '0');  // Add the last digit of sum to result
            carry = sum / 2;  // Update carry
        }

        reverse(result.begin(), result.end());  // Reverse to get the correct order
        return result;
    }
};