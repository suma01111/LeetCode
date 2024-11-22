class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int I[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romanLetter[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; num != 0; i++) { 
            while(num >= I[i]) {  
                num -= I[i];
                result += romanLetter[i];
            }
        }
        return result;
    }
};
/* example , 
num=1994 , condition num >= I[i], 
num = 1994-1000, result = M
num = 994-900, result = MCM {string add}
num = 94-90, result = MCMXC
num = 4-4, result = MCMXCIV
*/