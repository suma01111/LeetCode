class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bitLen = 0;

        for (int i = 1; i <= n; i++) {
            // check if i is power of 2
            if ((i & (i - 1)) == 0) {
                bitLen++;
            }

            ans = ((ans << bitLen) + i) % MOD;
        }

        return ans;
    }
};
/*
Dry Run (n = 3)
i	binary	bitLen	ans calculation	    ans
1	1	        1	(0 << 1) + 1	    1
2	10	        2	(1 << 2) + 2	    6
3	11	        2	(6 << 2) + 3	    27
*/