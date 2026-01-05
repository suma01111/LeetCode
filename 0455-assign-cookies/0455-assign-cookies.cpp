class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;   // i → children, j → cookies
        int count = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {   // cookie satisfies child
                count++;
                i++;
                j++;
            } else {
                j++;  // cookie too small, try bigger one
            }
        }

        return count;
    }
};
