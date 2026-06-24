class Solution {
    long long digCal(int _n){
        long long n = 1LL*_n;
        long long sum=0;
        long long sq=0;
        
        while(n>0){
            int dig = n%10;
            sum+= dig;
            sq += dig*dig;

            n=n/10;
        }

        return sq-sum;
    }

public:
    bool checkGoodInteger(int n) {
        long long ans = digCal(n);
        return ans>=50;
    }
};