class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;;
        int cnt=0;
        while(x>0){
            //count number of 1s in Xor, they denoted diff bits needed to convert
            cnt += (x&1);
            x=x>>1;
        }

        return cnt;
    }
};