class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};

// n      = 1010
// n>>1   = 0101
// x      = 1111
// x+1    = 10000
// x&(x+1)= 0  → true
