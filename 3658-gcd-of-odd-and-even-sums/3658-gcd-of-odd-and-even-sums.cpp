class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evenSum=n*(n+1);
        int oddSum= n*n;
        //gcd(n^2, n(n+1))=n -> basically return n

        return __gcd(evenSum,oddSum);

    }
};