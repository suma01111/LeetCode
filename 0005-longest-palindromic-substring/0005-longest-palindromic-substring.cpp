class Solution {
public:
    string longestPalindrome(string s) {
        //have to take two cases -> odd and even
        
        //base case
        if(s.length() <= 1)
            return s;
        
        string com = "";// To store the longest palindrome found

        for(int i=0; i < s.length() ; i++){ //left first and last digit from iteration
            //Odd string check
            int low = i;
            int high = i;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                low--;
                high++;
            }
            string palindrome = s.substr(low + 1, high - low - 1); // Correct use of substr
            if(palindrome.length() > com.length()){
            com = palindrome;
            }

        //Even string check
        low = i;
        high = i+1;
        while (low >= 0 && high < s.length() && s[low] == s[high]) {
                low--;
                high++;
            }
        palindrome = s.substr(low + 1, high - low - 1);
        if(palindrome.length() > com.length()){
            com = palindrome;
    }
   
    }
     return com;
    }
};