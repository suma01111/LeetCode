class Solution {
public:
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        long long ans = power(5,even)*power(4,odd) % MOD;
        return ans;
    }

    long long MOD = 1e9 + 7;
    long long power(long long a, long long eO){ //eO=even/odd
        long long ans = 1;
        while(eO > 0){
            if(eO % 2)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            eO /= 2;
        }

        return ans;
    }
};