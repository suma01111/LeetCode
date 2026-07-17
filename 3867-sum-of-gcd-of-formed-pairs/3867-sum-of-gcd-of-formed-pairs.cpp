class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefixGcd;
        prefixGcd.reserve(n);

        long long mx = 0;

        for (int x : nums) {
            mx = max(mx, (long long)x);
            prefixGcd.push_back(gcd(x, mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};