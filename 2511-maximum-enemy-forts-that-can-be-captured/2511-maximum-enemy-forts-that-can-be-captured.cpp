class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        int prev = -1; // previous non-zero fort

        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] != 0) {
                if (prev != -1 && forts[i] != forts[prev]) {
                    ans = max(ans, i - prev - 1);
                }
                prev = i;
            }
        }

        return ans;
    }
};