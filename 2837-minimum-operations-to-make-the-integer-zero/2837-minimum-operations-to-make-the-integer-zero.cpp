class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long diff = 1LL * num1 - 1LL * k * num2;

            if (diff < 0) {
                continue;
            }

            int bits = __builtin_popcountll(diff);

            if (bits <= k && diff >= k) {
                return k;
            }
        }
        return -1;
    }
};