
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int odd = 0;
        int ans = 0;
        int cnt = 0;   // counts valid left shifts

        for (int r = 0; r < nums.size(); r++) {

            if (nums[r] % 2 == 1) {
                odd++;
                cnt = 0;   // reset count when new odd comes
            }

            while (odd == k) {
                cnt++; //count even number which dont affect odd cnt string
                if (nums[l] % 2 == 1) odd--;
                l++;
            }

            ans += cnt;
        }

        return ans;
    }
};
