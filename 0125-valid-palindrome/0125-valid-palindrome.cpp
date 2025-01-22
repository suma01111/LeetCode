class Solution {
public:
    bool isPalindrome(string s) {
        //s string is declared which only contain lowercase alphanumeric characters (letter or number)
        string filtered;

        for(char c : s){
            if(isalnum(c)){
                filtered += tolower(c);
            }
        }

        int left = 0;
        int right = filtered.size()-1;

        while(left<right){
            if(filtered[left] != filtered[right]) return false;

            left++;
            right--;
        }
        return true;
    }
};