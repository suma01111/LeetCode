// XOR (^) gives the sum without carry
// AND (&) followed by left shift (<< 1) gives the carry

class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int carry = (a&b)<<1;
        a = a^b;
        b = carry;
        }
    return a;
    } 
};