class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        // lookup array
        vector<bool> seen(n + 1, false);

        // mark existing numbers
        for(int num : nums) {
            if(num > 0 && num <= n) {
                seen[num] = true;
            }
        }

        // find first missing positive
        for(int i = 1; i <= n; i++) {
            if(seen[i] == false) {
                return i;
            }
        }

        // if all numbers 1..n present
        return n + 1;
    }
};

/* initially
seen = [false,false,false,false,false]
index    0     1     2     3     4

Traverse original array.

If number is: positive within range [1,n] then mark it present.
seen[num] = true;

Traverse from 1 → n
First number not marked is the answer.

If all numbers 1..n are present, return n+1 number
*/