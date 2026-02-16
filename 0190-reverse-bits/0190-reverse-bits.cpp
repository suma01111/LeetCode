class Solution {
public:
    int reverseBits(int n) {
        if(n==0) return 0;

        int result=0;
        for(int i=0;i<32;i++){
            result <<= 1; //left shift by 1
            result = (result | (n&1) ) ;// LSB of n OR with res
            n >>= 1; //right shift by 1 (removing LSB)
        }
        return result;
    }
};

// Example: n = 1010 (binary)
// Iter1: result=0<<1 |0 = 0, n=101 , GET LSB of n and then add in res(from last) then right shift n(to remove LSB)
// Iter2: result=0<<1 |1 = 1, n=10
// Iter3: result=1<<1 |0 = 10, n=1
// Iter4: result=10<<1|1 = 101 → bits reversed
