//square and multiple algo (crypto)

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // convert to long long    
        if (N < 0) {
            x = 1.0 / x;      
            N = -N;
        }

        double ans = 1.0;
        while (N > 0) {
            if (N & 1) {      
                ans *= x;
            }
            x *= x;           
            N >>= 1;          
        }
        return ans;
    }
};

/*
| N  | Odd/Even | ans                   | x                    |
| -- | -------- | --------------------- | -------------------- |
| 34 | even     | 1                     | 16                   |
| 17 | odd      | 16                    | 256                  |
| 8  | even     | 16                    | 65536                |
| 4  | even     | 16                    | 4294967296           |
| 2  | even     | 16                    | 18446744073709551616 |
| 1  | odd      | 295147905179352825856 | —                    |

*/