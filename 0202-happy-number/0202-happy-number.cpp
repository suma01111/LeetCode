class Solution {
public:
    int next(int n){
        int sum =0;
        while(n>0){
            int dig = n % 10; //last digit
            sum += dig*dig;
            n = n/10; //remove last dig;
        }
        return sum;
    }


public:
    bool isHappy(int n) {
        int slow =n, fast =n;
        do{
            slow=next(slow);
            fast=next(next(fast));
        }while (slow != fast);

        return slow == 1;
    }
};