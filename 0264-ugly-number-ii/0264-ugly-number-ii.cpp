class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> ugly(n);
        ugly[0] = 1;

        int x2 = 0, x3 = 0, x5 = 0;

        for (int i = 1; i < n; i++) {
            long long nextUgly = min({
                ugly[x2] * 2,
                ugly[x3] * 3,
                ugly[x5] * 5
            });

            ugly[i] = nextUgly;

            if (nextUgly == ugly[x2] * 2) x2++;
            if (nextUgly == ugly[x3] * 3) x3++;
            if (nextUgly == ugly[x5] * 5) x5++;
        }

        return ugly[n - 1];
    }
};