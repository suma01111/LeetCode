class Solution {
public:
    int countEven(int num) {
        return sumDig(num);
    }

    int sumDig(int x) {
        int cnt=0;

        for (int n=1;n<=x;n++) {
            int temp=n; //IMP, we cant chnage n itself
            int sum=0;

            while(temp>0) {
                sum+=temp%10;
                temp/=10;
            }
            if (sum%2==0) cnt++;
        }

        return cnt;
    }
};

/*
MISTAKE
Inside the while loop, you're modifying n itself:

while(n > 0){
    int dig = n % 10;
    sum += dig;
    n = n / 10;   // n becomes 0
}

After the loop, n becomes 0, and then the for loop does n++, making it 1 again. This causes the loop to behave incorrectly (it can even become an infinite loop).
*/