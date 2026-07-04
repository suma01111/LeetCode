//by me
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return getReverse(num);
    }

    bool getReverse(int n){
        int reverse=0;
        string original= to_string(n);

        while(n>0){
            int dig=n%10;
            reverse= reverse*10 + dig;
            n=n/10;
        }
        
        string r = to_string(reverse);

        return (original.size() == r.size());
    }
};

//OPTIMAL
// class Solution {
// public:
//     bool isSameAfterReversals(int num) {
//         return (num == 0 || num % 10 != 0);
//     }
// };
// Time Complexity
// O(1)
// Space Complexity
// O(1)