//prefix priority : all numbers beginning with 1 (1, 10, 11, 100) appear before any number starting with 2 
//Dictionary number : the number 10 comes before 2 because "1" is smaller than "2"

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexi;
        int curr = 1;

        // Generate numbers from 1 to n
        for(int i=0;i<n;i++){
            lexi.push_back(curr);

            if(curr * 10 <= n ){
                curr = curr*10; 
            }
            else{
                // Adjust the current number by moving up one digit
                while (curr % 10 == 9 || curr >= n) {
                    curr /= 10;  // Remove the last digit
                }
                curr += 1;  // Increment the number
            }
        }
        return lexi;
    }
};