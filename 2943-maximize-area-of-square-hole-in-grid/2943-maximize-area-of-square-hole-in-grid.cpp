class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int longestH = longestConsecutive(hBars);
        int longestV = longestConsecutive(vBars);

        int side = min(longestH + 1, longestV + 1);
        return side * side;
    }

private:
    int longestConsecutive(vector<int>& arr) {
        if (arr.empty()) return 0;
        sort(arr.begin(), arr.end());

        int maxLen = 1, currLen = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1) {
                currLen++;
                maxLen = max(maxLen, currLen);
            } else {
                currLen = 1;
            }
        }
        return maxLen;
    }
};
