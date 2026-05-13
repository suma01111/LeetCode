class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int x = min(a, b);
            int y = max(a, b);

            // Initially 2 moves for all sums
            diff[2] += 2;

            // 1 move range
            diff[x + 1] -= 1;
            diff[y + limit + 1] += 1;

            // 0 move at exact sum
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};