class Solution {
public:

    // Returns the valid ending index for substring starting at 'start'
    // Returns -1 if no valid substring can start here.
    int getRight(string &s, vector<int> &first, vector<int> &last, int start) {
        int right = last[s[start] - 'a'];

        for (int i = start; i <= right; i++) {
            // Character starts before current interval
            if (first[s[i] - 'a'] < start)
                return -1;

            // Expand interval if needed
            right = max(right, last[s[i] - 'a']);
        }
        return right;
    }

    // Approach:
    // 1. Find first and last occurrence of every character.
    // 2. Consider only first occurrences as possible starts.
    // 3. Expand the interval until it contains all occurrences
    //    of every character inside it.
    // 4. Store all valid intervals.
    // 5. Greedily pick non-overlapping intervals with the smallest end.

    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n);
        vector<int> last(26, -1);

        // First & last occurrence
        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> intervals;
        // Build all valid intervals
        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a'])
                continue;
            int right = getRight(s, first, last, i);
            if (right != -1)
                intervals.push_back({i, right});
        }

        // Sort by ending index
        sort(intervals.begin(), intervals.end(),
            [](auto &a, auto &b) {
                if (a.second == b.second)
                    return a.first < b.first;
                return a.second < b.second;
            });

        vector<string> ans;
        int prevEnd = -1;
        // Greedily select non-overlapping intervals
        for (auto &it : intervals) {
            int l = it.first;
            int r = it.second;

            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};