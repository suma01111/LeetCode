//by me
class Solution {
    long long helper(long long n){
        long long num=0;

        while(n>0){
            int dig=n%10;
            n=n/10;
            if(dig==0) continue;
            num=(num*10) +dig;
        }
        string s = to_string(num); //IMPPP 
        reverse(s.begin(), s.end());
        return stoll(s);//REMEMBER
    }
public:
    long long removeZeros(long long n) {
        return helper(n);
    }
};