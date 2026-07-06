class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        int res=0, left=-1, right=-1;

        sort(A.begin(),A.end());

        for (auto &v : A) {
            if (v[0]>left && v[1]>right) {
                left=v[0];
                res++;
            }
            right=max(right, v[1]);
        }

        return res;
    }
};

/*
        // res = number of intervals that are NOT covered
        // left = start of the last interval counted
        // right = maximum end point seen so far

        // Traverse all intervals
        for (auto &v : A) {

            // Current interval is NOT covered if:
            // 1. Its start is greater than the last counted interval's start.
            // 2. Its end extends beyond every interval seen so far.
            if (v[0] > left && v[1] > right) {

                // Update the latest counted interval's start
                left = v[0];

                // Count this interval
                ++res;
            }

            // Always keep track of the farthest ending point seen so far
            right = max(right, v[1]);
        }

        // Return the number of intervals that remain
        return res;
    }
};
*/