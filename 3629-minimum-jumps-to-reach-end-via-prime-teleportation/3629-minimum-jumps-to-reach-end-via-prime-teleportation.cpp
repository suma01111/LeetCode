class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int MAXV = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor
        vector<int> spf(MAXV + 1);

        for (int i = 0; i <= MAXV; i++)
            spf[i] = i;

        for (int i = 2; i * i <= MAXV; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // prime -> indices divisible by prime
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                mp[p].push_back(i);

                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        vector<bool> usedPrime(MAXV + 1, false);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1)
                return d;

            // left
            if (i > 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            // teleport only if val itself is prime
            if (val > 1 && spf[val] == val && !usedPrime[val]) {

                for (int nxt : mp[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }

                // IMPORTANT OPTIMIZATION
                mp[val].clear();

                usedPrime[val] = true;
            }
        }

        return -1;
    }
};