class Solution {
public:
    int binaryGap(int n) {
        int last = -1;      // position of previous 1
        int maxDist = 0;
        int pos = 0;        // current bit position

        while (n > 0) {
            if (n & 1) {   // if current bit is 1
                if (last != -1) {
                    maxDist = max(maxDist, pos - last);
                }
                last = pos;
            }
            pos++;
            n >>= 1;       // move to next bit
        }

        return maxDist;
    }
};