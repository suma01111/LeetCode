class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();

        int maxOdd  = 0;
        int minEven = n+1;

        vector<int> vec(26, 0); //IMPORTANT
        for(char &ch : s) {
            vec[ch-'a']++; //IMPORTANT
        }

        for(int i = 0; i < 26; i++) {
            if(vec[i] == 0)
                continue;

            if(vec[i]%2 == 0) {
                minEven = min(minEven, vec[i]);
            } else {
                maxOdd = max(maxOdd, vec[i]);
            }
        }

        return maxOdd - minEven;
    }
};

/*
English lowercase letters range from 'a' to 'z', i.e., 26 letters total.
This line creates a vector vec of size 26, all initialized to 0.
Each index in the vector corresponds to a letter:
vec[0] → frequency of 'a'
vec[1] → frequency of 'b'
...
vec[25] → frequency of 'z'

ch - 'a' calculates the index for that letter:
For example, if ch = 'c', then 'c' - 'a' = 2 → it increments vec[2] by 1.

*/
