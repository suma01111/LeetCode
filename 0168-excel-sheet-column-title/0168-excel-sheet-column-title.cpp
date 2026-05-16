class Solution {
public:
    string convertToTitle(int colNum) {
        string ans;
        while(colNum>0){
            colNum --;

            int remainder = colNum%26;
            ans+= remainder +'A';
            colNum = colNum/26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*
// Excel columns are 1-based:
            // A = 1, B = 2, ..., Z = 26
            //
            // But modulo operation works naturally with 0-based indexing:
            // A = 0, B = 1, ..., Z = 25
            //
            // So before taking modulo,
            // we reduce colNum by 1 to shift it to 0-based indexing.

    // Convert number to character
            // 0 -> A
            // 1 -> B
            // ...
            // 25 -> Z
            ans += (remainder + 'A');
*/