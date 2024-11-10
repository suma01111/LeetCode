#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = static_cast<long>(sqrt(c));  // Use sqrt from <cmath> and cast to long

        while (a <= b) {
            long target = a * a + b * b;
            if (target == c) {
                return true;
            } else if (target < c) {
                a++;
            } else {
                b--;  // Decrement b when target is greater than c
            }
        }
        return false;
    }
};
