class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = (m+n-2);
        int r = min(m-1,n-1); 
        double ans=1; 

        // Compute:
        // C(N, r) = N! / (r! * (N-r)!)
        // Efficiently as:    ((N-r+1)/1) * ((N-r+2)/2) * ... * (N/r)
        for(int i=1;i<=r;i++){
            ans = ans*  (N-r+i)/i ;  //dont use ans *= (N-r+i)/i ; 
        }

        return (int)ans;
    }
};

/*
Robot must make exactly:
(m-1) down moves
(n-1) right moves

Total moves:(m+n−2)

We just choose positions of downs (or rights).
So answer:
(
    m+n−2 
    m−1
) P&C wala pattern

*/